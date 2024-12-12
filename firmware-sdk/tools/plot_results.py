import time
import serial
import struct
import binascii
import matplotlib.pyplot as plt
import re

def encode_and_send(string, ser):
    array_to_write = string.encode()
    ser.write(array_to_write)
    print("Sent: {} Size: {}".format(array_to_write, len(array_to_write)))

def await_response_exact(response, ser):
    data_in = b""
    while data_in != response.encode():
        data_in = ser.readline()
        print(data_in)
        if data_in == b"TIMEOUT\r\n":
            break
    return data_in.decode()

def await_response(response, ser):
    data_in = b""
    while response.encode() not in data_in:
        data_in = ser.readline()
        print(data_in)
        if data_in == b"TIMEOUT\r\n":
            break
    return data_in.decode()

def base64_encode(features):
    feature_byte_array = struct.pack('@' + 'f' * len(features), *features)
    res = binascii.b2a_base64(feature_byte_array, newline=False)

    print(len(features))
    print(len(features * 4))
    print(features)
    print(str(res)[2:-1])
    return str(res)[2:-1]

def send_uart(data, raw_data_len, ser, sim_timeout=False):
    data_sent = 0

    time.sleep(2)

    encode_and_send("AT\r", ser)
    response = await_response_exact("> ", ser)

    encode_and_send("AT+RUNIMPULSECONT\r", ser)
    response = await_response("OK", ser)

    chunk_size = int(''.join(filter(str.isdigit, response)))
    print("Chunk size is {}".format(chunk_size))

    data_modulo = len(data) % chunk_size
    if data_modulo:
        print("Data size before padding {}".format(len(data)))
        data = data + "=" * (chunk_size - data_modulo)
        print("Data size after padding {}".format(len(data)))

    while data_sent < len(data):
        encode_and_send("{}".format(data[data_sent:data_sent + chunk_size]), ser)
        time.sleep(0.01)
        data_sent += chunk_size
        print("Total sent: {}".format(data_sent))
        response = await_response("OK", ser)

        if sim_timeout:
            time.sleep(0.1)
        if response == "TIMEOUT\r\n":
            print("Data send time out. Terminating...")
            ser.close()
            sys.exit(1)

    response = await_response_exact("END OUTPUT\r\n", ser)
    ser.close()

if __name__ == "__main__":
    ser = serial.Serial('COM16', 115200, timeout=0.050)

    # Initialize storage for plotting
    baby_cry_values = []
    indoor_room_noises_values = []
    unknown_values = []
    timestamps = []
    time_window = 20  # Time window in seconds

    plt.ion()  # Turn on interactive plotting
    fig, ax = plt.subplots()

    start_time = time.time()

    try:
        while True:
            line = ser.readline().decode(errors='ignore').strip()
            current_time = time.time() - start_time

            if line.startswith('baby_cry:'):
                baby_cry = float(re.search(r'baby_cry: (\d\.\d+)', line).group(1))
                baby_cry_values.append(baby_cry)

            if line.startswith('indoor_room_noises:'):
                indoor_room_noises = float(re.search(r'indoor_room_noises: (\d\.\d+)', line).group(1))
                indoor_room_noises_values.append(indoor_room_noises)

            if line.startswith('unknown:'):
                unknown = float(re.search(r'unknown: (\d\.\d+)', line).group(1))
                unknown_values.append(unknown)

                # Add a timestamp for each complete set of values
                timestamps.append(current_time)

                # Keep only data within the time window
                while timestamps and (current_time - timestamps[0]) > time_window:
                    timestamps.pop(0)
                    baby_cry_values.pop(0)
                    indoor_room_noises_values.pop(0)
                    unknown_values.pop(0)

                # Update the plot
                ax.clear()
                ax.plot(timestamps, baby_cry_values, label='baby_cry', marker='o')
                ax.plot(timestamps, indoor_room_noises_values, label='indoor_room_noises', marker='o')
                ax.plot(timestamps, unknown_values, label='unknown', marker='o')
                ax.set_xlabel('Time (seconds)')
                ax.set_ylabel('Prediction Values')
                ax.set_title('Prediction Results Over Last {} Seconds'.format(time_window))
                ax.legend()
                ax.grid()
                plt.pause(0.1)

    except KeyboardInterrupt:
        print("Terminated by user.")

    finally:
        ser.close()
        plt.ioff()
        plt.show()
 