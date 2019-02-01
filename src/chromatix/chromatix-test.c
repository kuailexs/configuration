#include "chromatix.h"
#include <dlfcn.h>
#include <stdio.h>

#include "chromatix-test.h"



int main(int argc, char **argv) {

	void* chromatix_handle = dlopen("./libchromatix_imx214_snapshot.so",
	RTLD_NOW);
	if (chromatix_handle == NULL) {
		printf("ERROR:%s:dlopen\n", dlerror());
		return -1;
	}

	chromatix_parms_type* (*open_lib)() = (chromatix_parms_type* (*)())dlsym(chromatix_handle, "load_chromatix");

	if (open_lib == NULL) {
		printf("ERROR:%s:dlsym\n", dlerror());
		return -1;
	}

	chromatix_parms_type * bb = open_lib();

	printf("0x%hx,\n", bb->chromatix_version);
	printf("%hd,\n", bb->is_compressed);
	printf("%hd,\n", bb->revision_number);

	chromatix_VFE_type vfe_type = bb->chromatix_VFE;
	print_chromatix_VFE_type(vfe_type);

	dlclose(chromatix_handle);

	return 0;
}

void print_chromatix_VFE_type(chromatix_VFE_type vfe_type) {
	printf("{\n");

	chromatix_black_level_type chromatix_black_level =
			vfe_type.chromatix_black_level;
	print_chromatix_black_level_type(chromatix_black_level);

	chromatix_channel_balance_gains_type chromatix_channel_balance_gains =
			vfe_type.chromatix_channel_balance_gains;
	print_chromatix_channel_balance_gains_type(chromatix_channel_balance_gains);

	chromatix_ABF2_type chromatix_ABF2 =  vfe_type.chromatix_ABF2;
	print_chromatix_ABF2_type(chromatix_ABF2);

	chromatix_BPC_type chromatix_BPC;
	chromatix_demosaic_type chromatix_demosaic;
	chromatix_CL_filter_type chromatix_CL_filter;
	chromatix_CC_type chromatix_CC;
	chromatix_gamma_type chromatix_gamma;
	chromatix_CV_type chromatix_CV;
	chromatix_ASF_5x5_type chromatix_ASF_5x5;
	chromatix_ASF_7x7_type chromatix_ASF_7x7;
	chromatix_LA_type chromatix_LA;
	chromatix_CS_MCE_type chromatix_CS_MCE;
	chromatix_wavelet_type chromatix_wavelet;
	chromatix_temporal_denoise_type chromatix_temporal_denoise;
	chromatix_SCE_type chromatix_SCE;
	chromatix_grid_stats_type chromatix_grid_stats;
	chromatix_skin_detection_type chromatix_skin_detection;

	printf("},\n");
}

/************ chromatix_ABF2_type  *********/
void print_chromatix_ABF2_type(chromatix_ABF2_type chromatix_ABF2){

}

/************ chromatix_ABF2_type  *********/


/************ chromatix_channel_balance_gains_type  *********/
void print_chromatix_channel_balance_gains_type(
		chromatix_channel_balance_gains_type chromatix_channel_balance_gains) {
	printf("{");
	printf("%f", chromatix_channel_balance_gains.green_even);
	printf("f,");
	printf("%f", chromatix_channel_balance_gains.green_odd);
	printf("f,");
	printf("%f", chromatix_channel_balance_gains.red);
	printf("f,");
	printf("%f,", chromatix_channel_balance_gains.blue);
	printf("},\n");
}

/************ chromatix_channel_balance_gains_type  *********/

/************ chromatix_black_level_type  *********/
void print_chromatix_black_level_type(
		chromatix_black_level_type chromatix_black_level) {
	printf("{\n");
	printf("%hd,\n", chromatix_black_level.control_blk);

	trigger_point_type blk_lowlight_trigger =
			chromatix_black_level.blk_lowlight_trigger;
	print_trigger_point_type(
			blk_lowlight_trigger);

	printf("%hd,\n", chromatix_black_level.max_blk_increase);

	chromatix_4_channel_black_level normal_light_4_channel =
			chromatix_black_level.normal_light_4_channel;
	print_chromatix_4_channel_black_level(
			normal_light_4_channel);

	printf("},\n");
}
void print_trigger_point_type(
		trigger_point_type blk_lowlight_trigger) {
	printf("{\n");
	printf("%f", blk_lowlight_trigger.gain_start);
	printf("f,\n");
	printf("%f", blk_lowlight_trigger.gain_end);
	printf("f,\n");
	printf("%ld,\n", blk_lowlight_trigger.lux_index_start);
	printf("%ld,\n", blk_lowlight_trigger.lux_index_end);
	printf("},\n");
}
void print_chromatix_4_channel_black_level(
		chromatix_4_channel_black_level normal_light_4_channel) {
	printf("{");
	printf("%hd,", normal_light_4_channel.black_even_row_even_col);
	printf("%hd,", normal_light_4_channel.black_even_row_odd_col);
	printf("%hd,", normal_light_4_channel.black_odd_row_even_col);
	printf("%hd,", normal_light_4_channel.black_odd_row_odd_col);
	printf("},\n");
}
/************ chromatix_black_level_type  *********/


