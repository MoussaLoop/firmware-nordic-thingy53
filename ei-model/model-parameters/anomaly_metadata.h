/* Generated by Edge Impulse
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _EI_CLASSIFIER_ANOMALY_METADATA_H_
#define _EI_CLASSIFIER_ANOMALY_METADATA_H_

#include "edge-impulse-sdk/classifier/ei_model_types.h"

const uint16_t ei_classifier_anom_axes[] = { 0, 11, 22 };

// (before - mean) / scale
const float ei_classifier_anom_scale[3] = { 4.598740245868833, 3.0765670669068275, 2.0936788450296744 };
const float ei_classifier_anom_mean[3] = { 4.124793295218616, 2.8621887842689953, 2.2566755305631605 };
const ei_classifier_anom_cluster_t ei_classifier_anom_clusters[32] = {
	{ ( float[3] ) { -0.8932448029518127, -0.9206010103225708, -1.055553674697876 }, 0.4470645428184733 },
	{ ( float[3] ) { -0.18241187930107117, 1.3848332166671753, -0.047954872250556946 }, 0.42830165703609474 },
	{ ( float[3] ) { -0.4504140019416809, -0.04526648297905922, 1.1496057510375977 }, 0.4817484234886305 },
	{ ( float[3] ) { -0.5834709405899048, -0.35021767020225525, 1.3669097423553467 }, 0.37220008077614464 },
	{ ( float[3] ) { -0.2954768240451813, -0.11168535053730011, 2.333683729171753 }, 0.9817868209123946 },
	{ ( float[3] ) { 1.8227709531784058, 0.5206660032272339, 0.3602268397808075 }, 0.4279324073934871 },
	{ ( float[3] ) { -0.32054704427719116, 0.0277141984552145, 2.9795162677764893 }, 0.4374596003416974 },
	{ ( float[3] ) { 1.1567201614379883, -0.10969613492488861, -0.4102109372615814 }, 0.38317461151408405 },
	{ ( float[3] ) { 1.3525092601776123, -0.40143728256225586, -0.3112473487854004 }, 0.466828434008558 },
	{ ( float[3] ) { -0.6314368844032288, -0.35236579179763794, -0.8216263055801392 }, 0.3814117448048944 },
	{ ( float[3] ) { 2.1414542198181152, -0.05724303796887398, 0.84588223695755 }, 0.5895870538532866 },
	{ ( float[3] ) { 1.5402109622955322, -0.053585249930620193, -0.46989989280700684 }, 0.4915380545547231 },
	{ ( float[3] ) { 1.9902774095535278, 0.13205686211585999, 0.2858063578605652 }, 0.44408042785538204 },
	{ ( float[3] ) { -0.4095689654350281, -0.41872698068618774, 2.001028537750244 }, 0.46251514886678874 },
	{ ( float[3] ) { 1.2707867622375488, -0.349385142326355, 0.4139760732650757 }, 0.627481609353895 },
	{ ( float[3] ) { -0.48359188437461853, 0.22327746450901031, -0.15212193131446838 }, 0.6686675979834836 },
	{ ( float[3] ) { -0.689568817615509, -0.5933825373649597, 0.9085447192192078 }, 0.5202181515223988 },
	{ ( float[3] ) { 0.036015499383211136, 0.597315788269043, 0.6806364059448242 }, 0.7051987524738385 },
	{ ( float[3] ) { -0.15625694394111633, 2.0199453830718994, 0.5861085057258606 }, 0.5923044839365236 },
	{ ( float[3] ) { -0.5007128715515137, 0.0011004800908267498, 1.620482087135315 }, 0.7754288372504752 },
	{ ( float[3] ) { -0.25164303183555603, 2.3025894165039062, -0.022419728338718414 }, 0.45031655575652996 },
	{ ( float[3] ) { -0.6264173984527588, -0.22340011596679688, -0.5954493880271912 }, 0.40691003252064817 },
	{ ( float[3] ) { -0.2699184715747833, 2.9313976764678955, -0.40592721104621887 }, 0.46208382077994153 },
	{ ( float[3] ) { -0.33236002922058105, 0.5607204437255859, 0.017955400049686432 }, 0.47169106089591994 },
	{ ( float[3] ) { -0.6082421541213989, 0.8714585900306702, 0.4365161657333374 }, 0.3361789236021611 },
	{ ( float[3] ) { 1.601772427558899, 0.3413149118423462, -0.1020779013633728 }, 0.4518917976982427 },
	{ ( float[3] ) { 0.023918867111206055, 3.3287479877471924, -0.2869546711444855 }, 0.6382735446770751 },
	{ ( float[3] ) { 0.16685347259044647, 2.778691530227661, 0.9372643828392029 }, 0.4354407772215489 },
	{ ( float[3] ) { 1.1784796714782715, 2.876598358154297, 0.9817097187042236 }, 0.250403063586309 },
	{ ( float[3] ) { 0.9565476179122925, 2.422194242477417, 0.6233457326889038 }, 0.3802966654676634 },
	{ ( float[3] ) { 0.30768105387687683, 1.7980595827102661, 2.729546308517456 }, 0.9890028083954134 },
	{ ( float[3] ) { 0.13079512119293213, 2.6247451305389404, 1.5065226554870605 }, 0.7232549406313342 },
};

#endif // _EI_CLASSIFIER_ANOMALY_METADATA_H_