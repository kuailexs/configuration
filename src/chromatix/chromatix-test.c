#include "chromatix.h"
#include <dlfcn.h>
#include <stdio.h>

#include "chromatix-test.h"

int main(int argc, char **argv) {

	void* chromatix_handle = dlopen(
			"/system/vendor/lib/libchromatix_imx214_snapshot.so",
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
	printf("%hhu,\n", bb->is_compressed);
	printf("%hd,\n", bb->revision_number);

	chromatix_VFE_type vfe_type = bb->chromatix_VFE;
	print_chromatix_VFE_type(vfe_type);

	dlclose(chromatix_handle);

	return 0;
}
void print_chromatix_CCT_trigger_type(chromatix_CCT_trigger_type a) {
	printf("{\n");
	print_unsigned_long(a.CCT_start);
	print_unsigned_long(a.CCT_end);
	printf("},\n");
}

void print_unsigned_long(unsigned long a) {
	printf("%lu,\n", a);
}

void print_unsigned_short(unsigned short a) {
	printf("%hd,\n", a);
}
void print_unsigned_char(unsigned char a) {
	printf("%hhu,\n", a);
}
void print_unsigned_int(unsigned int a) {
	printf("%u,\n", a);
}
void print_long(long a) {
	printf("%ld,\n", a);
}

void print_short(short a) {
	printf("%hd,\n", a);
}
void print_char(char a) {
	printf("%hhu,\n", a);
}
void print_int(int a) {
	printf("%d,\n", a);
}
void print_float(float a) {
	printf("%f", a);
	printf("f,\n");
}
void print_chromatix_asf_7_7_type(chromatix_asf_7_7_type a) {
	printf("{\n");
	print_unsigned_char(a.asf_en);
	for (int i = 0; i < ASF_7x7_MAX_LIGHT; i++) {
		printf("[\n");
		print_int(a.sp[i]);
		printf("]\n");
	}
	print_unsigned_char(a.en_sp_eff);
	print_unsigned_char(a.neg_abs_y1);
	for (int i = 0; i < 3; i++) {
		printf("[\n");
		print_int(a.nz[i]);
		printf("]\n");
	}
	printf("},\n");
}
void print_chromatix_asf_5_5_type(chromatix_asf_5_5_type a) {
	printf("{\n");
	print_unsigned_long(a.filter_mode);
	print_float(a.normalize_factor1);
	print_float(a.normalize_factor2);
	print_matrix_5_5_type(a.filter1);
	print_matrix_5_5_type(a.filter2);
	print_unsigned_char(a.extraction_factor);
	for (int i = 0; i < ASF_MAX_LIGHT; i++) {
		printf("[\n");
		print_asf_setting_type(a.setting[i]);
		printf("]\n");
	}
	printf("},\n");
}
void print_asf_setting_type(asf_setting_type a) {
	printf("{\n");
	print_char(a.lower_threshold);
	print_char(a.upper_threshold);
	print_char(a.negative_threshold);
	print_char(a.upper_threshold_f2);
	print_char(a.negative_threshold_f2);
	print_float(a.sharpen_degree_f1);
	print_float(a.sharpen_degree_f2);
	print_unsigned_char(a.smoothing_percent);
	print_unsigned_char(a.smoothing_percent_5x5);
	printf("},\n");
}
void print_matrix_5_5_type(matrix_5_5_type a) {
	printf("{\n");
	print_short(a.a11);
	print_short(a.a12);
	print_short(a.a13);
	print_short(a.a14);
	print_short(a.a15);

	print_short(a.a21);
	print_short(a.a22);
	print_short(a.a23);
	print_short(a.a24);
	print_short(a.a25);

	print_short(a.a31);
	print_short(a.a32);
	print_short(a.a33);
	print_short(a.a34);
	print_short(a.a35);

	print_short(a.a41);
	print_short(a.a42);
	print_short(a.a43);
	print_short(a.a44);
	print_short(a.a45);

	print_short(a.a51);
	print_short(a.a52);
	print_short(a.a53);
	print_short(a.a54);
	print_short(a.a55);
	printf("},\n");
}
void print_chromatix_rscs_stat_config_type(chromatix_rscs_stat_config_type a) {
	printf("{\n");
	print_int(a.row_sum_enable);
	print_float(a.row_sum_hor_Loffset_ratio);
	print_float(a.row_sum_ver_Toffset_ratio);
	print_float(a.row_sum_hor_Roffset_ratio);
	print_float(a.row_sum_ver_Boffset_ratio);
	print_unsigned_char(a.row_sum_V_subsample_ratio);
	print_int(a.col_sum_enable);
	print_float(a.col_sum_hor_Loffset_ratio);
	print_float(a.col_sum_ver_Toffset_ratio);
	print_float(a.col_sum_hor_Roffset_ratio);
	print_float(a.col_sum_ver_Boffset_ratio);
	print_unsigned_char(a.col_sum_H_subsample_ratio);
	printf("},\n");
}
void print_chromatix_wb_exp_stats_type(chromatix_wb_exp_stats_type a) {
	printf("{\n");
	print_unsigned_char(a.y_min);
	print_unsigned_char(a.y_max);
	print_char(a.m1);
	print_char(a.m2);
	print_char(a.m3);
	print_char(a.m4);
	print_short(a.c1);
	print_short(a.c2);
	print_short(a.c3);
	print_short(a.c4);
	printf("},\n");
}
void print_chromatix_black_level_offset_type(
		chromatix_black_level_offset_type a) {
	printf("{\n");
	print_unsigned_short(a.even_columns);
	print_unsigned_short(a.odd_columns);
	printf("},\n");
}
void print_chromatix_VFE_type(chromatix_VFE_type vfe_type) {
	printf("{\n");

	chromatix_black_level_type chromatix_black_level =
			vfe_type.chromatix_black_level;
	print_chromatix_black_level_type(chromatix_black_level);

	chromatix_channel_balance_gains_type chromatix_channel_balance_gains =
			vfe_type.chromatix_channel_balance_gains;
	print_chromatix_channel_balance_gains_type(chromatix_channel_balance_gains);

	chromatix_ABF2_type chromatix_ABF2 = vfe_type.chromatix_ABF2;
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
void print_chromatix_ABF2_type(chromatix_ABF2_type chromatix_ABF2) {

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
	print_unsigned_char(chromatix_black_level.control_blk);

	trigger_point_type blk_lowlight_trigger =
			chromatix_black_level.blk_lowlight_trigger;
	print_trigger_point_type(blk_lowlight_trigger);

	printf("%hd,\n", chromatix_black_level.max_blk_increase);

	chromatix_4_channel_black_level normal_light_4_channel =
			chromatix_black_level.normal_light_4_channel;
	print_chromatix_4_channel_black_level(normal_light_4_channel);

	printf("},\n");
}
void print_trigger_point_type(trigger_point_type blk_lowlight_trigger) {
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
	print_unsigned_short(normal_light_4_channel.black_even_row_even_col);
	print_unsigned_short(normal_light_4_channel.black_even_row_odd_col);
	print_unsigned_short(normal_light_4_channel.black_odd_row_even_col);
	print_unsigned_short(normal_light_4_channel.black_odd_row_odd_col);
	printf("},\n");
}
/************ chromatix_black_level_type  *********/

