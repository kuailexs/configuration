

#ifndef CHROMATIX_CHROMATIX_TEST_H_
#define CHROMATIX_CHROMATIX_TEST_H_

#include "chromatix-test.h"

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

void print_chromatix_version_type(chromatix_version_type a) {
    print_unsigned_short(a);
}

void print_chromatix_number_elements_type(chromatix_number_elements_type a) {
    print_unsigned_short(a);
}

void print_tuning_control_type(tuning_control_type a) {
    print_unsigned_char(a);
}

void print_trigger_point_type(trigger_point_type a) {
    printf("{");
    print_float(a.gain_start);
    print_float(a.gain_end);
    print_long(a.lux_index_start);
    print_long(a.lux_index_end);
    printf("},\n");
}

void print_chromatix_CCT_trigger_type(chromatix_CCT_trigger_type a) {
    printf("{");
    print_unsigned_long(a.CCT_start);
    print_unsigned_long(a.CCT_end);
    printf("},\n");
}

void print_chromatix_black_level_offset_type(chromatix_black_level_offset_type a) {
    printf("{");
    print_unsigned_short(a.even_columns);
    print_unsigned_short(a.odd_columns);
    printf("},\n");
}

void print_chromatix_4_channel_black_level(chromatix_4_channel_black_level a) {
    printf("{");
    print_unsigned_short(a.black_even_row_even_col);
    print_unsigned_short(a.black_even_row_odd_col);
    print_unsigned_short(a.black_odd_row_even_col);
    print_unsigned_short(a.black_odd_row_odd_col);
    printf("},\n");
}

void print_chromatix_wb_exp_stats_type(chromatix_wb_exp_stats_type a) {
    printf("{");
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

void print_chromatix_rscs_stat_config_type(chromatix_rscs_stat_config_type a) {
    printf("{");
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

void print_matrix_5_5_type(matrix_5_5_type a) {
    printf("{");
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

void print_normalize_factor_type(normalize_factor_type a) {
    print_float(a);
}

void print_filter_threshold_type(filter_threshold_type a) {
    print_char(a);
}

void print_filter_sharpen_degree_type(filter_sharpen_degree_type a) {
    print_float(a);
}

void print_filter_smoothing_degree_type(filter_smoothing_degree_type a) {
    print_unsigned_char(a);
}

void print_asf_setting_type(asf_setting_type a) {
    printf("{");
    print_filter_threshold_type(a.lower_threshold);
    print_filter_threshold_type(a.upper_threshold);
    print_filter_threshold_type(a.negative_threshold);
    print_filter_threshold_type(a.upper_threshold_f2);
    print_filter_threshold_type(a.negative_threshold_f2);
    print_filter_sharpen_degree_type(a.sharpen_degree_f1);
    print_filter_sharpen_degree_type(a.sharpen_degree_f2);
    print_filter_smoothing_degree_type(a.smoothing_percent);
    print_filter_smoothing_degree_type(a.smoothing_percent_5x5);
    printf("},\n");
}

void print_chromatix_asf_5_5_type(chromatix_asf_5_5_type a) {
    printf("{");
    print_unsigned_long(a.filter_mode);
    print_normalize_factor_type(a.normalize_factor1);
    print_normalize_factor_type(a.normalize_factor2);
    print_matrix_5_5_type(a.filter1);
    print_matrix_5_5_type(a.filter2);
    print_unsigned_char(a.extraction_factor);
    printf("{");
    for(int i = 0 ; i < ASF_MAX_LIGHT ; i++) {
        print_asf_setting_type(a.setting[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_asf_7_7_type(chromatix_asf_7_7_type a) {
    printf("{");
    print_unsigned_char(a.asf_en);
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.sp[i]);
    }
    printf("},");
    print_unsigned_char(a.en_sp_eff);
    print_unsigned_char(a.neg_abs_y1);
    printf("{");
    for(int i = 0 ; i < 3 ; i++) {
        print_int(a.nz[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 16 ; j++) {
            print_float(a.f1[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 16 ; j++) {
            print_float(a.f2[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 16 ; j++) {
            print_float(a.f3[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 16 ; j++) {
            print_float(a.f4[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 16 ; i++) {
        print_float(a.f5[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 24 ; j++) {
            print_float(a.lut1[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 24 ; j++) {
            print_float(a.lut2[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.en_dyna_clamp[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_float(a.smax[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.omax[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_float(a.smin[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.omin[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.reg_hh[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.reg_hl[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.reg_vh[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        print_int(a.reg_vl[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ASF_7x7_MAX_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 12 ; j++) {
            print_float(a.lut3[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_color_correction_type(chromatix_color_correction_type a) {
    printf("{");
    print_float(a.c0);
    print_float(a.c1);
    print_float(a.c2);
    print_float(a.c3);
    print_float(a.c4);
    print_float(a.c5);
    print_float(a.c6);
    print_float(a.c7);
    print_float(a.c8);
    print_short(a.k0);
    print_short(a.k1);
    print_short(a.k2);
    print_unsigned_char(a.q_factor);
    printf("},\n");
}

void print_chromatix_manual_white_balance_type(chromatix_manual_white_balance_type a) {
    printf("{");
    print_float(a.r_gain);
    print_float(a.g_gain);
    print_float(a.b_gain);
    printf("},\n");
}

void print_chromatix_gamma_table_type(chromatix_gamma_table_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < GAMMA_TABLE_SIZE ; i++) {
        print_unsigned_char(a.gamma[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chroma_enhancement_type(chroma_enhancement_type a) {
    printf("{");
    print_float(a.a_m);
    print_float(a.a_p);
    print_float(a.b_m);
    print_float(a.b_p);
    print_float(a.c_m);
    print_float(a.c_p);
    print_float(a.d_m);
    print_float(a.d_p);
    print_short(a.k_cb);
    print_short(a.k_cr);
    printf("},\n");
}

void print_luma_calculation_type(luma_calculation_type a) {
    printf("{");
    print_float(a.v0);
    print_float(a.v1);
    print_float(a.v2);
    print_unsigned_short(a.k);
    printf("},\n");
}

void print_chromatix_color_conversion_type(chromatix_color_conversion_type a) {
    printf("{");
    print_chroma_enhancement_type(a.chroma);
    print_luma_calculation_type(a.luma);
    printf("},\n");
}

void print_chromatix_adaptive_bayer_filter_data_type2(chromatix_adaptive_bayer_filter_data_type2 a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < 3 ; i++) {
        print_unsigned_short(a.threshold_red[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 2 ; i++) {
        print_float(a.scale_factor_red[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 3 ; i++) {
        print_unsigned_short(a.threshold_green[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 2 ; i++) {
        print_float(a.scale_factor_green[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 2 ; i++) {
        print_float(a.a[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 3 ; i++) {
        print_unsigned_short(a.threshold_blue[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 2 ; i++) {
        print_float(a.scale_factor_blue[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 16 ; i++) {
        print_float(a.table_pos[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 8 ; i++) {
        print_float(a.table_neg[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_luma_filter_type(chromatix_luma_filter_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < 3 ; i++) {
        print_unsigned_short(a.threshold[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 2 ; i++) {
        print_float(a.scale_factor[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 16 ; i++) {
        print_float(a.table_pos[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 8 ; i++) {
        print_float(a.table_neg[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_auto_flicker_detection_data_type(chromatix_auto_flicker_detection_data_type a) {
    printf("{");
    print_int(a.AFD_continuous_enable);
    print_float(a.std_threshold);
    print_unsigned_char(a.percent_threshold);
    print_unsigned_long(a.diff_threshold);
    print_unsigned_long(a.frame_ct_threshold);
    print_unsigned_char(a.num_frames);
    print_unsigned_char(a.frame_skip);
    print_unsigned_long(a.num_rows);
    print_unsigned_char(a.num_frames_settle);
    print_unsigned_char(a.num_peaks_threshold);
    print_float(a.INTL_adj_factor);
    printf("},\n");
}

void print_cs_luma_threshold_type(cs_luma_threshold_type a) {
    printf("{");
    print_unsigned_char(a.cs_luma_threshold1);
    print_unsigned_char(a.cs_luma_threshold2);
    print_unsigned_char(a.cs_luma_threshold3);
    print_unsigned_char(a.cs_luma_threshold4);
    print_unsigned_char(a.cs_chroma_threshold1);
    print_unsigned_char(a.cs_chroma_threshold2);
    printf("},\n");
}

void print_bayer_histogram_config_type(bayer_histogram_config_type a) {
    printf("{");
    print_float(a.horizontalOffsetRatio);
    print_float(a.verticalOffsetRatio);
    print_float(a.horizontalWindowRatio);
    print_float(a.verticalWindowRatio);
    printf("},\n");
}

void print_bayer_grid_config_type(bayer_grid_config_type a) {
    printf("{");
    print_unsigned_char(a.saturation_thresh_R);
    print_unsigned_char(a.saturation_thresh_Gr);
    print_unsigned_char(a.saturation_thresh_Gb);
    print_unsigned_char(a.saturation_thresh_B);
    print_float(a.horizontalOffsetRatio);
    print_float(a.verticalOffsetRatio);
    print_float(a.horizontalWindowRatio);
    print_float(a.verticalWindowRatio);
    print_unsigned_short(a.num_H_regions);
    print_unsigned_short(a.num_V_regions);
    printf("},\n");
}

void print_LA_args_type(LA_args_type a) {
    printf("{");
    print_unsigned_char(a.shadow_range);
    print_unsigned_char(a.shadow_boost_allowance);
    print_unsigned_char(a.LA_reduction_fine_tune);
    print_unsigned_char(a.highlight_suppress_fine_tune);
    print_unsigned_char(a.shadow_boost_fine_tune);
    printf("},\n");
}

void print_mce_type(mce_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < 4 ; i++) {
        print_unsigned_char(a.green_y[i]);
    }
    printf("},");
    print_float(a.green_boost_factor);
    print_char(a.green_cr_boundary);
    print_char(a.green_cb_boundary);
    print_unsigned_char(a.green_cr_transition_width);
    print_unsigned_char(a.green_cb_transition_width);
    print_unsigned_short(a.green_bright_index);
    print_unsigned_short(a.green_dark_index);
    printf("{");
    for(int i = 0 ; i < 4 ; i++) {
        print_unsigned_char(a.blue_y[i]);
    }
    printf("},");
    print_float(a.blue_boost_factor);
    print_char(a.blue_cr_boundary);
    print_char(a.blue_cb_boundary);
    print_unsigned_char(a.blue_cr_transition_width);
    print_unsigned_char(a.blue_cb_transition_width);
    print_unsigned_short(a.blue_bright_index);
    print_unsigned_short(a.blue_dark_index);
    printf("{");
    for(int i = 0 ; i < 4 ; i++) {
        print_unsigned_char(a.red_y[i]);
    }
    printf("},");
    print_float(a.red_boost_factor);
    print_char(a.red_cr_boundary);
    print_char(a.red_cb_boundary);
    print_unsigned_char(a.red_cr_transition_width);
    print_unsigned_char(a.red_cb_transition_width);
    print_unsigned_short(a.red_bright_index);
    print_unsigned_short(a.red_dark_index);
    printf("},\n");
}

void print_cr_cb_point(cr_cb_point a) {
    printf("{");
    print_int(a.cr);
    print_int(a.cb);
    printf("},\n");
}

void print_cr_cb_triangle(cr_cb_triangle a) {
    printf("{");
    print_cr_cb_point(a.point1);
    print_cr_cb_point(a.point2);
    print_cr_cb_point(a.point3);
    printf("},\n");
}

void print_sce_cr_cb_triangle_set(sce_cr_cb_triangle_set a) {
    printf("{");
    print_cr_cb_triangle(a.triangle1);
    print_cr_cb_triangle(a.triangle2);
    print_cr_cb_triangle(a.triangle3);
    print_cr_cb_triangle(a.triangle4);
    print_cr_cb_triangle(a.triangle5);
    printf("},\n");
}

void print_sce_affine_transform_2d(sce_affine_transform_2d a) {
    printf("{");
    print_float(a.a);
    print_float(a.b);
    print_float(a.c);
    print_float(a.d);
    print_float(a.e);
    print_float(a.f);
    printf("},\n");
}

void print_bpc_4_offset_type(bpc_4_offset_type a) {
    printf("{");
    print_unsigned_short(a.bpc_4_offset_r_hi);
    print_unsigned_short(a.bpc_4_offset_r_lo);
    print_unsigned_short(a.bpc_4_offset_gr_hi);
    print_unsigned_short(a.bpc_4_offset_gr_lo);
    print_unsigned_short(a.bpc_4_offset_gb_hi);
    print_unsigned_short(a.bpc_4_offset_gb_lo);
    print_unsigned_short(a.bpc_4_offset_b_hi);
    print_unsigned_short(a.bpc_4_offset_b_lo);
    printf("},\n");
}

void print_demosaic3_LUT_type(demosaic3_LUT_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < 18 ; i++) {
        print_float(a.wk[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 18 ; i++) {
        print_int(a.bk[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 18 ; i++) {
        print_int(a.lk[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 18 ; i++) {
        print_int(a.Tk[i]);
    }
    printf("},");
    printf("},\n");
}

void print_Chroma_filter_type(Chroma_filter_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < 4 ; i++) {
        print_float(a.h[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 2 ; i++) {
        print_float(a.v[i]);
    }
    printf("},");
    printf("},\n");
}

void print_ReferenceNoiseProfile_type(ReferenceNoiseProfile_type a) {
    printf("{");
    print_float(a.trigger_value);
    printf("{");
    for(int i = 0 ; i < NUM_NOISE_PROFILE ; i++) {
        print_float(a.referenceNoiseProfileData[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < WAVELET_LEVEL ; i++) {
        print_float(a.denoise_scale_y[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < WAVELET_LEVEL ; i++) {
        print_float(a.denoise_scale_chroma[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < WAVELET_LEVEL ; i++) {
        print_float(a.denoise_edge_softness_y[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < WAVELET_LEVEL ; i++) {
        print_float(a.denoise_edge_softness_chroma[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < WAVELET_LEVEL ; i++) {
        print_float(a.denoise_weight_y[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < WAVELET_LEVEL ; i++) {
        print_float(a.denoise_weight_chroma[i]);
    }
    printf("},");
    print_int(a.sw_denoise_edge_threshold_y);
    print_int(a.sw_denoise_edge_threshold_chroma);
    printf("},\n");
}

void print_wavelet_denoise_type(wavelet_denoise_type a) {
    printf("{");
    print_int(a.wavelet_enable_index);
    print_tuning_control_type(a.control_denoise);
    printf("{");
    for(int i = 0 ; i < NUM_GRAY_PATCHES ; i++) {
        print_ReferenceNoiseProfile_type(a.noise_profile[i]);
    }
    printf("},");
    printf("},\n");
}

void print_temporal_noise_profile_type(temporal_noise_profile_type a) {
    printf("{");
    print_float(a.y);
    print_float(a.cb);
    print_float(a.cr);
    printf("},\n");
}

void print_reference_temporal_noise_profile_type(reference_temporal_noise_profile_type a) {
    printf("{");
    print_float(a.trigger_value);
    print_temporal_noise_profile_type(a.referenceNoiseProfileData);
    print_float(a.temporal_denoise_scale_y);
    print_float(a.temporal_denoise_scale_chroma);
    printf("},\n");
}

void print_scene_change_detect_type(scene_change_detect_type a) {
    printf("{");
    print_int(a.enable);
    print_float(a.aec_para_mean);
    print_float(a.aec_para_std);
    print_unsigned_short(a.aec_dy_window);
    print_unsigned_short(a.threshold_aec_lux);
    print_float(a.af_range_threshold);
    printf("},\n");
}

void print_snow_scene_detect_type(snow_scene_detect_type a) {
    printf("{");
    print_int(a.snow_scene_detection_enable);
    print_unsigned_long(a.y_cloudy_snow_threshold);
    print_unsigned_long(a.awb_y_max_in_grey);
    print_unsigned_long(a.min_snow_cloudy_sample_th);
    print_unsigned_long(a.extreme_snow_cloudy_sample_th);
    print_float(a.extreme_luma_target_offset);
    print_unsigned_long(a.severe_snow_scene_cap);
    print_float(a.snowscene_aggressiveness);
    print_unsigned_char(a.ui_snow_cloudy_display_th);
    printf("},\n");
}

void print_backlit_scene_detect_type(backlit_scene_detect_type a) {
    printf("{");
    print_int(a.backlight_detection_enable);
    print_unsigned_long(a.low_luma_threshold);
    print_unsigned_long(a.high_luma_threshold);
    print_float(a.low_luma_count_percent_threshold);
    print_float(a.high_luma_count_percent_threshold);
    print_LA_args_type(a.backlight_la_8k_config);
    print_int(a.backlight_max_la_luma_target_offset);
    print_float(a.backlit_aggressiveness);
    print_float(a.max_percent_threshold);
    print_unsigned_char(a.ui_backlit_display_th);
    printf("},\n");
}

void print_red_eye_reduction_type(red_eye_reduction_type a) {
    printf("{");
    print_int(a.red_eye_reduction_xenon_strobe_enable);
    print_int(a.red_eye_reduction_led_flash_enable);
    print_int(a.number_of_preflash_cycles);
    print_int(a.preflash_interval_between_pulese);
    print_int(a.preflash_Xenon_pulese_duration);
    print_int(a.preflash_LED_pulse_duration);
    print_int(a.preflash_LED_current);
    printf("},\n");
}

void print_landscape_scene_detect_type(landscape_scene_detect_type a) {
    printf("{");
    print_int(a.landscape_detection_enable);
    print_float(a.landscape_red_boost_factor);
    print_float(a.landscape_green_boost_factor);
    print_float(a.landscape_blue_boost_factor);
    print_float(a.min_blue_green_content_detection_threshold);
    print_float(a.max_blue_green_content_detecton_threshold);
    print_int(a.green_offset_rg);
    print_int(a.green_offset_bg);
    print_float(a.asd_ext_blue_th);
    print_float(a.asd_ext_green_th_r);
    print_float(a.asd_ext_green_th_b);
    print_float(a.aggressiveness);
    print_long(a.lux_idx_indoor);
    print_long(a.lux_idx_outdoor);
    print_unsigned_char(a.ui_landscape_display_th);
    printf("},\n");
}

void print_portrait_scene_detect_type(portrait_scene_detect_type a) {
    printf("{");
    print_int(a.portrait_detection_enable);
    print_float(a.skin_color_boost_factor);
    print_float(a.min_face_content_threshold);
    print_float(a.max_face_content_threshold);
    print_filter_sharpen_degree_type(a.soft_focus_degree_7_7);
    print_filter_sharpen_degree_type(a.soft_focus_degree_5_5);
    print_float(a.aggressiveness);
    print_unsigned_char(a.ui_portrait_display_th);
    printf("},\n");
}

void print_chromatix_channel_balance_gains_type(chromatix_channel_balance_gains_type a) {
    printf("{");
    print_float(a.green_even);
    print_float(a.green_odd);
    print_float(a.red);
    print_float(a.blue);
    printf("},\n");
}

void print_chromatix_awb_weight_vector_type(chromatix_awb_weight_vector_type a) {
    printf("{");
    print_int(a.indoor_weight);
    print_int(a.outdoor_weight);
    print_int(a.inoutdoor_weight);
    printf("},\n");
}

void print_chromatix_awb_sample_influence_type(chromatix_awb_sample_influence_type a) {
    printf("{");
    print_float(a.outdoor_influence);
    print_float(a.indoor_influence);
    printf("},\n");
}

void print_chromatix_awb_reference_type(chromatix_awb_reference_type a) {
    printf("{");
    print_float(a.RG_ratio);
    print_float(a.BG_ratio);
    printf("},\n");
}

void print_chromatix_awb_gain_adj_type(chromatix_awb_gain_adj_type a) {
    printf("{");
    print_float(a.red_gain_adj);
    print_float(a.blue_gain_adj);
    printf("},\n");
}

void print_AWB_purple_prevent_type(AWB_purple_prevent_type a) {
    printf("{");
    print_int(a.AWB_purple_prevent_enable);
    print_tuning_control_type(a.control_purple_prevent);
    print_trigger_point_type(a.purple_prevent_trigger);
    print_float(a.purple_sky_prevention_bg_threshold);
    printf("},\n");
}

void print_AWB_motion_sensor_type(AWB_motion_sensor_type a) {
    printf("{");
    print_float(a.gyro_trigger);
    print_float(a.accelerometer_trigger);
    print_float(a.magnetometer_trigger);
    print_float(a.DIS_motion_vector_trigger);
    printf("},\n");
}

void print_low_light_adj_type(low_light_adj_type a) {
    printf("{");
    print_int(a.lux_index);
    print_float(a.green_rg_offset_adj);
    print_float(a.green_bg_offset_adj);
    print_float(a.outlier_dist_adj);
    printf("},\n");
}

void print_awb_lowlight_adj_lut_type(awb_lowlight_adj_lut_type a) {
    printf("{");
    print_unsigned_char(a.enable);
    printf("{");
    for(int i = 0 ; i < MAX_LOW_LIGHT_AWB_LUT_SIZE ; i++) {
        print_low_light_adj_type(a.lut_entry[i]);
    }
    printf("},");
    printf("},\n");
}

void print_LED_mix_type(LED_mix_type a) {
    printf("{");
    print_unsigned_short(a.CCT);
    print_unsigned_short(a.LED1_setting);
    print_unsigned_short(a.LED2_setting);
    printf("},\n");
}

void print_chromatix_match_LED_lighting_table_type(chromatix_match_LED_lighting_table_type a) {
    printf("{");
    print_unsigned_short(a.table_size);
    printf("{");
    for(int i = 0 ; i < MAX_LED_MIX_LEVEL ; i++) {
        print_LED_mix_type(a.CCT_control[i]);
    }
    printf("},");
    printf("},\n");
}

void print_exposure_entry_type(exposure_entry_type a) {
    printf("{");
    print_unsigned_short(a.gain);
    print_unsigned_long(a.line_count);
    printf("},\n");
}

void print_chromatix_exposure_table_type(chromatix_exposure_table_type a) {
    printf("{");
    print_unsigned_char(a.exp_table_flag);
    print_unsigned_short(a.valid_entries);
    print_int(a.aec_enable_digital_gain_for_EV_lowlight);
    print_unsigned_short(a.exp_index_for_digital_gain_for_EV_lowlight);
    printf("{");
    for(int i = 0 ; i < MAX_EXPOSURE_TABLE_SIZE ; i++) {
        print_exposure_entry_type(a.exposure_entries[i]);
    }
    printf("},");
    printf("},\n");
}

void print_aec_outdoor_bright_region_type(aec_outdoor_bright_region_type a) {
    printf("{");
    print_int(a.is_supported);
    print_float(a.reduction);
    print_unsigned_long(a.threshold_LO);
    print_unsigned_long(a.lux_index_LO);
    print_unsigned_long(a.threshold_HI);
    print_unsigned_long(a.lux_index_HI);
    print_float(a.discard_ratio);
    printf("},\n");
}

void print_aec_dark_region_type(aec_dark_region_type a) {
    printf("{");
    print_int(a.is_supported);
    print_float(a.threshold_LO);
    print_float(a.threshold_HI);
    print_float(a.discard_ratio);
    printf("},\n");
}

void print_aec_motion_iso_type(aec_motion_iso_type a) {
    printf("{");
    print_int(a.motion_iso_enable);
    print_float(a.motion_iso_aggressiveness);
    print_float(a.motion_iso_threshold);
    print_float(a.motion_iso_max_gain);
    printf("},\n");
}

void print_snapshot_trade_off_table_type(snapshot_trade_off_table_type a) {
    printf("{");
    print_unsigned_short(a.lux_index);
    print_float(a.gain_trade_off);
    print_float(a.max_exp_time);
    printf("},\n");
}

void print_snapshot_exposure_type(snapshot_exposure_type a) {
    printf("{");
    print_int(a.enable);
    print_int(a.exposure_stretch_enable);
    print_unsigned_char(a.valid_entries);
    printf("{");
    for(int i = 0 ; i < MAX_SNAPSHOT_LUT_SIZE ; i++) {
        print_snapshot_trade_off_table_type(a.snapshot_ae_table[i]);
    }
    printf("},");
    printf("},\n");
}

void print_AEC_strobe_flash_type(AEC_strobe_flash_type a) {
    printf("{");
    print_int(a.strobe_enable);
    print_unsigned_long(a.strobe_min_time);
    print_float(a.intersect_time_gain);
    print_float(a.post_intersect_strobe_flux_rate_increase);
    print_float(a.max_strobe_gain);
    print_int(a.strobe_flash_lux_idx_trigger);
    printf("},\n");
}

void print_AEC_touch_type(AEC_touch_type a) {
    printf("{");
    print_int(a.touch_roi_enable);
    print_float(a.touch_roi_weight);
    printf("},\n");
}

void print_AEC_face_priority_type(AEC_face_priority_type a) {
    printf("{");
    print_int(a.aec_face_enable);
    print_float(a.aec_face_weight);
    print_float(a.dark_skin_ratio);
    print_float(a.light_skin_ratio);
    print_long(a.dark_skin_luma_target);
    print_long(a.light_skin_luma_target);
    printf("},\n");
}

void print_hist_weight_type(hist_weight_type a) {
    printf("{");
    print_int(a.pixel_value);
    print_float(a.weight);
    printf("},\n");
}

void print_AE_hist_flat_detector_type(AE_hist_flat_detector_type a) {
    printf("{");
    print_int(a.hist_flat_detector_enable);
    print_int(a.start_level);
    print_int(a.end_level);
    print_int(a.range);
    print_float(a.delta_th);
    print_float(a.bright_flat_det_th);
    print_float(a.dark_flat_det_th);
    print_float(a.bright_flat_tail_det);
    print_float(a.dark_flat_tail_det);
    printf("},\n");
}

void print_AEC_bayer_stats_algo_params_type(AEC_bayer_stats_algo_params_type a) {
    printf("{");
    print_int(a.bright_region_influence_adj_enable);
    print_int(a.bright_weight_lux_idx_trigger);
    print_float(a.bright_weight_def);
    print_int(a.bright_level);
    print_int(a.color_based_metering_enable);
    print_float(a.col_sat_weight);
    print_float(a.color_luma_decrease_ratio);
    print_float(a.rg_ratio_lth);
    print_float(a.rg_ratio_hth);
    print_float(a.bg_ratio_lth);
    print_float(a.bg_ratio_hth);
    print_float(a.flat_white_grey_vs_nongrey_th);
    print_float(a.flat_dark_grey_vs_nongrey_th);
    print_int(a.hist_ent_enable);
    printf("{");
    for(int i = 0 ; i < HIST_WEIGHT_SIZE ; i++) {
        print_hist_weight_type(a.hist_weight_table[i]);
    }
    printf("},");
    print_float(a.luma_target_reset_ratio);
    print_float(a.hist_luma_target_adjusment_cap);
    print_float(a.near_grey_tolerance);
    print_AE_hist_flat_detector_type(a.hist_flat_detect);
    print_float(a.bright_flat_compensation_ratio);
    print_float(a.dark_flat_compensation_ratio);
    printf("},\n");
}

void print_shake_table_type(shake_table_type a) {
    printf("{");
    print_float(a.exposure_time);
    print_float(a.no_shake_threshold);
    print_float(a.moderate_shake_threshold);
    printf("},\n");
}

void print_shake_detection_type(shake_detection_type a) {
    printf("{");
    print_int(a.enable);
    print_unsigned_char(a.valid_entries);
    printf("{");
    for(int i = 0 ; i < MAX_SHAKE_LUT_SIZE ; i++) {
        print_shake_table_type(a.shake_table[i]);
    }
    printf("},");
    printf("},\n");
}

void print_ASD_struct_type(ASD_struct_type a) {
    printf("{");
    print_int(a.ASD_Software_Type);
    print_scene_change_detect_type(a.scene_change_detect);
    print_snow_scene_detect_type(a.snow_scene_detect);
    print_backlit_scene_detect_type(a.backlit_scene_detect);
    print_landscape_scene_detect_type(a.landscape_scene_detect);
    print_portrait_scene_detect_type(a.portrait_scene_detect);
    print_chromatix_color_conversion_type(a.sunset_color_conversion);
    print_chromatix_color_conversion_type(a.skintone_color_conversion);
    print_chromatix_color_conversion_type(a.skintone_color_conversion_d65);
    print_chromatix_color_conversion_type(a.skintone_color_conversion_a);
    printf("},\n");
}

void print_AEC_algo_struct_type(AEC_algo_struct_type a) {
    printf("{");
    print_int(a.AEC_Software_Type);
    print_float(a.color_correction_global_gain);
    print_chromatix_exposure_table_type(a.chromatix_exposure_table);
    print_snapshot_exposure_type(a.snapshot_exposure_table);
    print_unsigned_char(a.default_luma_target);
    print_unsigned_char(a.outdoor_luma_target);
    print_long(a.luma_tolerance);
    print_float(a.exposure_index_adj_step);
    print_float(a.ISO100_gain);
    print_long(a.aec_indoor_index);
    print_long(a.aec_outdoor_index);
    print_float(a.max_snapshot_exposure_time_allowed);
    print_float(a.aggressiveness_values);
    print_unsigned_short(a.fix_fps_aec_table_index);
    print_unsigned_long(a.high_luma_region_threshold);
    print_aec_outdoor_bright_region_type(a.bright_region);
    print_aec_dark_region_type(a.dark_region);
    print_unsigned_short(a.wled_trigger_idx);
    print_float(a.aec_led_pre_flux);
    print_float(a.aec_led_flux_hi);
    print_float(a.aec_led_flux_med);
    print_float(a.aec_led_flux_low);
    print_aec_motion_iso_type(a.aec_motion_iso);
    print_int(a.aec_conv_holding_time_adj);
    print_float(a.max_video_fps);
    print_unsigned_short(a.max_sensitivity_lux_index);
    printf("{");
    for(int i = 0 ; i < NUM_AEC_STATS ; i++) {
        printf("{");
        for(int j = 0 ; j < NUM_AEC_STATS ; j++) {
            print_float(a.AEC_weight_center_weighted[i][j]);
        }
        printf("},");
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < NUM_AEC_STATS ; i++) {
        printf("{");
        for(int j = 0 ; j < NUM_AEC_STATS ; j++) {
            print_float(a.AEC_weight_spot_meter[i][j]);
        }
        printf("},");
    }
    printf("},");
    print_AEC_strobe_flash_type(a.AEC_strobe_flash);
    print_AEC_touch_type(a.AEC_touch);
    print_AEC_face_priority_type(a.AEC_face_priority);
    print_unsigned_long(a.aec_fast_convergence_skip);
    print_unsigned_long(a.aec_slow_convergence_skip);
    print_AEC_bayer_stats_algo_params_type(a.AEC_bayer_stats_algo_params);
    print_shake_detection_type(a.shake_detection);
    print_red_eye_reduction_type(a.red_eye_reduction);
    printf("},\n");
}

void print_AWB_algo_struct_type(AWB_algo_struct_type a) {
    printf("{");
    print_int(a.AWB_Software_Type);
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_chromatix_awb_reference_type(a.reference[i]);
    }
    printf("},");
    print_chromatix_awb_gain_adj_type(a.LED_gain_adj);
    print_chromatix_awb_gain_adj_type(a.strobe_gain_adj);
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_chromatix_awb_gain_adj_type(a.gain_adj[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_chromatix_awb_gain_adj_type(a.gain_adj_lowlight[i]);
    }
    printf("},");
    print_long(a.indoor_index);
    print_long(a.outdoor_index);
    print_float(a.snow_blue_gain_adj_ratio);
    print_float(a.beach_blue_gain_adj_ratio);
    print_int(a.outlier_distance);
    print_int(a.green_offset_rg);
    print_int(a.green_offset_bg);
    print_unsigned_char(a.skip_frames_after_changing_VFE);
    print_float(a.extreme_RG_ratio_threshold);
    print_float(a.extreme_BG_ratio_threshold);
    print_unsigned_short(a.compact_cluster_r2);
    print_unsigned_short(a.compact_cluster_to_ref_point_r2);
    print_unsigned_char(a.a_cluster_threshold);
    print_unsigned_char(a.f_cluster_threshold);
    print_unsigned_char(a.day_cluster_threshold);
    print_unsigned_char(a.outdoor_green_threshold);
    print_unsigned_char(a.outdoor_green_threshold_bright_F);
    print_unsigned_char(a.outdoor_green_threshold_dark_F);
    print_unsigned_char(a.day_cluster_threshold_for_F);
    print_unsigned_char(a.white_balance_allow_fline);
    print_unsigned_char(a.outdoor_valid_sample_cnt_threshold);
    print_unsigned_char(a.outdoor_green_upper_threshold);
    print_unsigned_short(a.r2_threshold);
    print_unsigned_char(a.outdoor_green_threshold_bright_A);
    print_unsigned_char(a.outdoor_green_threshold_dark_A);
    print_unsigned_char(a.day_cluster_threshold_for_A);
    print_chromatix_manual_white_balance_type(a.awb_min_gains);
    print_chromatix_manual_white_balance_type(a.awb_max_gains);
    print_chromatix_awb_sample_influence_type(a.sample_influence);
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_ALL_LIGHT ; i++) {
        print_chromatix_awb_weight_vector_type(a.awb_weight_vector[i]);
    }
    printf("},");
    print_int(a.awb_white_world_y_min_ratio);
    print_float(a.awb_aggressiveness);
    print_int(a.awb_self_cal_enable);
    print_float(a.awb_self_cal_adj_ratio_high);
    print_float(a.awb_self_cal_adj_ratio_low);
    print_unsigned_char(a.awb_enable_lock_heuristics_1);
    print_unsigned_char(a.awb_enable_lock_heuristics_2);
    print_unsigned_char(a.awb_enable_lock_heuristics_3);
    print_unsigned_char(a.awb_indoor_daylight_lock_enable);
    print_unsigned_char(a.awb_enable_white_world);
    print_AWB_purple_prevent_type(a.AWB_purple_prevent);
    print_unsigned_char(a.AWB_Ymin_low_threshold);
    print_unsigned_char(a.AWB_Ymin_high_threshold);
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_float(a.AWB_golden_module_R_Gr_ratio[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_float(a.AWB_golden_module_Gb_Gr_ratio[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_float(a.AWB_golden_module_B_Gr_ratio[i]);
    }
    printf("},");
    print_int(a.enable_AWB_module_cal);
    print_AWB_motion_sensor_type(a.AWB_motion_sensor_data);
    print_float(a.awb_led_strobe_adjustment_factor);
    print_unsigned_char(a.lowlight_toggle_enable);
    print_unsigned_char(a.awb_interpolate_gain_adj_enable);
    print_awb_lowlight_adj_lut_type(a.AWB_lowlight_LUT);
    print_chromatix_match_LED_lighting_table_type(a.mix_LED_table);
    printf("},\n");
}

void print_Bayer_AWB_parameters_type(Bayer_AWB_parameters_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_chromatix_awb_reference_type(a.reference[i]);
    }
    printf("},");
    print_chromatix_awb_gain_adj_type(a.LED_gain_adj);
    print_chromatix_awb_gain_adj_type(a.strobe_gain_adj);
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_chromatix_awb_gain_adj_type(a.gain_adj[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_LIGHT ; i++) {
        print_chromatix_awb_gain_adj_type(a.gain_adj_lowlight[i]);
    }
    printf("},");
    print_long(a.indoor_index);
    print_long(a.outdoor_index);
    print_float(a.snow_blue_gain_adj_ratio);
    print_float(a.beach_blue_gain_adj_ratio);
    print_int(a.outlier_distance);
    print_int(a.green_offset_rg);
    print_int(a.green_offset_bg);
    print_unsigned_char(a.skip_frames);
    print_chromatix_manual_white_balance_type(a.awb_min_gains);
    print_chromatix_manual_white_balance_type(a.awb_max_gains);
    print_float(a.awb_aggressiveness);
    print_int(a.awb_self_cal_enable);
    print_float(a.awb_self_cal_adj_ratio_high);
    print_float(a.awb_self_cal_adj_ratio_low);
    print_AWB_purple_prevent_type(a.AWB_purple_prevent);
    print_int(a.enable_AWB_module_cal);
    print_AWB_motion_sensor_type(a.AWB_motion_sensor_data);
    print_float(a.awb_led_strobe_adjustment_factor);
    print_unsigned_char(a.awb_interpolate_gain_adj_enable);
    print_awb_lowlight_adj_lut_type(a.AWB_lowlight_LUT);
    print_chromatix_match_LED_lighting_table_type(a.mix_LED_table);
    print_int(a.bright_green_percentage);
    print_int(a.dark_green_percentage);
    print_int(a.dark_r_threshold);
    print_int(a.dark_g_threshold);
    print_int(a.dark_b_threshold);
    print_int(a.white_stat_y_threshold_high);
    print_float(a.threshold_extreme_b_percent);
    print_float(a.threshold_extreme_r_percent);
    print_int(a.threshold_compact_cluster);
    print_int(a.compact_to_grey_dis);
    print_int(a.threshold_compact_cluster_valid);
    print_int(a.dominant_cluster_threshold);
    printf("{");
    for(int i = 0 ; i < AGW_NUMBER_GRID_POINT ; i++) {
        print_int(a.distance_weight_table[i]);
    }
    printf("},");
    print_int(a.outdoor_adjustment);
    print_int(a.exposure_adjustment);
    print_float(a.outlier_valid_ymax_ratio);
    print_float(a.cluster_high_pec);
    print_float(a.cluster_mid_pec);
    print_float(a.cluster_low_pec);
    printf("{");
    for(int i = 0 ; i < AGW_AWB_MAX_ALL_LIGHT ; i++) {
        printf("{");
        for(int j = 0 ; j < 4 ; j++) {
            print_int(a.weight_vector[i][j]);
        }
        printf("},");
    }
    printf("},");
    print_float(a.ref_b_bg_tl84);
    print_float(a.ref_r_rg_a);
    print_float(a.extreme_range_perc_b);
    print_float(a.extreme_range_perc_r);
    print_int(a.threshold_compact_cluster_grey);
    print_float(a.blue_sky_pec);
    print_float(a.blue_sky_pec_buffer);
    print_float(a.slope_factor_m);
    print_float(a.awb2_mcc_extreme_blue_threshold);
    printf("},\n");
}

void print_chromatix_black_level_type(chromatix_black_level_type a) {
    printf("{");
    print_tuning_control_type(a.control_blk);
    print_trigger_point_type(a.blk_lowlight_trigger);
    print_unsigned_short(a.max_blk_increase);
    print_chromatix_4_channel_black_level(a.normal_light_4_channel);
    printf("},\n");
}

void print_chromatix_ABF2_type(chromatix_ABF2_type a) {
    printf("{");
    print_tuning_control_type(a.control_abf2);
    print_unsigned_short(a.abf2_enable_index);
    print_trigger_point_type(a.abf2_low_light_trigger);
    print_trigger_point_type(a.abf2_bright_light_trigger);
    print_chromatix_adaptive_bayer_filter_data_type2(a.abf2_config_low_light);
    print_chromatix_adaptive_bayer_filter_data_type2(a.abf2_config_normal_light);
    print_chromatix_adaptive_bayer_filter_data_type2(a.abf2_config_bright_light);
    printf("},\n");
}

void print_chromatix_BPC_type(chromatix_BPC_type a) {
    printf("{");
    print_tuning_control_type(a.control_bpc);
    print_trigger_point_type(a.bpc_lowlight_trigger);
    print_unsigned_char(a.bpc_Fmin);
    print_unsigned_char(a.bpc_Fmax);
    print_unsigned_char(a.bpc_Fmin_lowlight);
    print_unsigned_char(a.bpc_Fmax_lowlight);
    printf("{");
    for(int i = 0 ; i < BPC_MAX_LIGHT ; i++) {
        print_bpc_4_offset_type(a.bpc_4_offset[i]);
    }
    printf("},");
    print_tuning_control_type(a.control_bcc);
    print_trigger_point_type(a.bcc_lowlight_trigger);
    print_unsigned_char(a.bcc_Fmin);
    print_unsigned_char(a.bcc_Fmax);
    print_unsigned_char(a.bcc_Fmin_lowlight);
    print_unsigned_char(a.bcc_Fmax_lowlight);
    printf("{");
    for(int i = 0 ; i < BPC_MAX_LIGHT ; i++) {
        print_bpc_4_offset_type(a.bcc_4_offset[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_demosaic_type(chromatix_demosaic_type a) {
    printf("{");
    print_tuning_control_type(a.control_demosaic3);
    print_trigger_point_type(a.demosaic3_trigger_lowlight);
    print_demosaic3_LUT_type(a.demosaic3_LUT);
    printf("{");
    for(int i = 0 ; i < LOWLIGHT_MAX_LIGHT ; i++) {
        print_float(a.demosaic3_aG[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < LOWLIGHT_MAX_LIGHT ; i++) {
        print_float(a.demosaic3_bL[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_CL_filter_type(chromatix_CL_filter_type a) {
    printf("{");
    print_tuning_control_type(a.control_chroma_filter);
    print_trigger_point_type(a.chroma_filter_trigger_lowlight);
    print_int(a.chroma_filter_enable_index);
    printf("{");
    for(int i = 0 ; i < LOWLIGHT_MAX_LIGHT ; i++) {
        print_Chroma_filter_type(a.chroma_filter[i]);
    }
    printf("},");
    print_tuning_control_type(a.control_LF);
    print_trigger_point_type(a.LF_low_light_trigger);
    print_trigger_point_type(a.LF_bright_light_trigger);
    print_int(a.LF_enable_index);
    print_chromatix_luma_filter_type(a.LF_config_low_light);
    print_chromatix_luma_filter_type(a.LF_config_normal_light);
    print_chromatix_luma_filter_type(a.LF_config_bright_light);
    printf("},\n");
}

void print_chromatix_CC_type(chromatix_CC_type a) {
    printf("{");
    print_tuning_control_type(a.control_cc);
    print_trigger_point_type(a.cc_trigger);
    print_chromatix_CCT_trigger_type(a.CC_A_trigger);
    print_chromatix_CCT_trigger_type(a.CC_Daylight_trigger);
    print_float(a.CC_LED_start);
    print_float(a.CC_LED_end);
    print_float(a.CC_strobe_start);
    print_float(a.CC_strobe_end);
    print_chromatix_color_correction_type(a.TL84_color_correction);
    print_chromatix_color_correction_type(a.lowlight_color_correction);
    print_chromatix_color_correction_type(a.D65_color_correction);
    print_chromatix_color_correction_type(a.A_color_correction);
    print_chromatix_color_correction_type(a.outdoor_color_correction);
    print_chromatix_color_correction_type(a.LED_color_correction);
    print_chromatix_color_correction_type(a.STROBE_color_correction);
    printf("},\n");
}

void print_chromatix_gamma_type(chromatix_gamma_type a) {
    printf("{");
    print_tuning_control_type(a.control_gamma);
    print_trigger_point_type(a.gamma_lowlight_trigger);
    print_trigger_point_type(a.gamma_outdoor_trigger);
    print_chromatix_gamma_table_type(a.default_gamma_table);
    print_chromatix_gamma_table_type(a.lowlight_gamma_table);
    print_chromatix_gamma_table_type(a.outdoor_gamma_table);
    printf("},\n");
}

void print_chromatix_CV_type(chromatix_CV_type a) {
    printf("{");
    print_tuning_control_type(a.control_cv);
    print_trigger_point_type(a.cv_trigger);
    print_chromatix_CCT_trigger_type(a.CV_A_trigger);
    print_chromatix_CCT_trigger_type(a.CV_Daylight_trigger);
    print_chromatix_color_conversion_type(a.TL84_color_conversion);
    print_chromatix_color_conversion_type(a.A_color_conversion);
    print_chromatix_color_conversion_type(a.daylight_color_conversion);
    print_chromatix_color_conversion_type(a.lowlight_color_conversion);
    print_chromatix_color_conversion_type(a.outdoor_color_conversion);
    print_chromatix_color_conversion_type(a.mono_color_conversion);
    print_chromatix_color_conversion_type(a.sepia_color_conversion);
    print_chromatix_color_conversion_type(a.negative_color_conversion);
    print_chromatix_color_conversion_type(a.aqua_color_conversion);
    print_float(a.saturated_color_conversion_factor);
    printf("},\n");
}

void print_chromatix_ASF_5x5_type(chromatix_ASF_5x5_type a) {
    printf("{");
    print_tuning_control_type(a.control_asf_5X5);
    print_trigger_point_type(a.asf_5x5_lowlight_trigger);
    print_trigger_point_type(a.asf_5x5_outdoor_trigger);
    print_chromatix_asf_5_5_type(a.asf_5_5);
    print_filter_sharpen_degree_type(a.soft_focus_degree_5_5);
    print_float(a.asf_5_5_sharp_min_ds_factor);
    print_float(a.asf_5_5_sharp_max_ds_factor);
    print_float(a.asf_5_5_sharp_max_factor);
    printf("},\n");
}

void print_chromatix_ASF_7x7_type(chromatix_ASF_7x7_type a) {
    printf("{");
    print_tuning_control_type(a.control_asf_7x7);
    print_trigger_point_type(a.asf_7x7_lowlight_trigger);
    print_trigger_point_type(a.asf_7x7_brightlight_trigger);
    print_chromatix_asf_7_7_type(a.asf_7_7);
    print_filter_sharpen_degree_type(a.soft_focus_degree_7_7);
    print_float(a.asf_7_7_sharp_min_ds_factor);
    print_float(a.asf_7_7_sharp_max_ds_factor);
    print_float(a.asf_7_7_sharp_max_factor);
    printf("},\n");
}

void print_chromatix_LA_type(chromatix_LA_type a) {
    printf("{");
    print_int(a.LA_enable);
    print_tuning_control_type(a.control_la);
    print_trigger_point_type(a.la_brightlight_trigger);
    print_LA_args_type(a.LA_config);
    print_LA_args_type(a.LA_config_outdoor);
    print_int(a.la_luma_target_adj);
    printf("},\n");
}

void print_chromatix_CS_MCE_type(chromatix_CS_MCE_type a) {
    printf("{");
    print_tuning_control_type(a.control_cs);
    print_trigger_point_type(a.cs_lowlight_trigger);
    print_cs_luma_threshold_type(a.cs_lowlight);
    print_cs_luma_threshold_type(a.cs_normal);
    print_unsigned_char(a.chroma_thresh_BW);
    print_unsigned_char(a.chroma_thresh_color);
    print_mce_type(a.mce_config);
    printf("},\n");
}

void print_chromatix_wavelet_type(chromatix_wavelet_type a) {
    printf("{");
    print_wavelet_denoise_type(a.wavelet_denoise_SW_420);
    print_wavelet_denoise_type(a.wavelet_denoise_SW_422);
    print_wavelet_denoise_type(a.wavelet_denoise_HW_420);
    print_wavelet_denoise_type(a.wavelet_denoise_HW_422);
    printf("},\n");
}

void print_chromatix_temporal_denoise_type(chromatix_temporal_denoise_type a) {
    printf("{");
    print_int(a.temporal_denoise_enable_index);
    print_tuning_control_type(a.control_temporal_denoise);
    printf("{");
    for(int i = 0 ; i < NUM_GRAY_PATCHES ; i++) {
        print_reference_temporal_noise_profile_type(a.temporal_noise_profile[i]);
    }
    printf("},");
    print_int(a.algorithm_select);
    printf("},\n");
}

void print_sce_shift_vector(sce_shift_vector a) {
    printf("{");
    print_float(a.cr);
    print_float(a.cb);
    printf("},\n");
}

void print_chromatix_SCE_type(chromatix_SCE_type a) {
    printf("{");
    print_int(a.sce_enable);
    print_tuning_control_type(a.control_SCE);
    print_trigger_point_type(a.SCE_trigger);
    print_chromatix_CCT_trigger_type(a.SCE_A_trigger);
    print_chromatix_CCT_trigger_type(a.SCE_D65_trigger);
    print_sce_cr_cb_triangle_set(a.origin_triangles_TL84);
    print_sce_cr_cb_triangle_set(a.destination_triangles_TL84);
    print_sce_shift_vector(a.shift_vector_TL84);
    print_sce_affine_transform_2d(a.outside_region_mapping);
    print_sce_cr_cb_triangle_set(a.origin_triangles_A);
    print_sce_cr_cb_triangle_set(a.destination_triangles_A);
    print_sce_shift_vector(a.shift_vector_A);
    print_sce_cr_cb_triangle_set(a.origin_triangles_D65);
    print_sce_cr_cb_triangle_set(a.destination_triangles_D65);
    print_sce_shift_vector(a.shift_vector_D65);
    printf("},\n");
}

void print_chromatix_grid_stats_type(chromatix_grid_stats_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < AWB_STATS_MAX_LIGHT ; i++) {
        print_chromatix_wb_exp_stats_type(a.wb_exp_stats[i]);
    }
    printf("},");
    print_chromatix_rscs_stat_config_type(a.rscs_cnfig);
    print_bayer_histogram_config_type(a.bayer_histogram_config);
    print_bayer_grid_config_type(a.AWB_AEC_stats_window);
    print_bayer_grid_config_type(a.bayer_exp_window);
    printf("},\n");
}

void print_chromatix_skin_detection_type(chromatix_skin_detection_type a) {
    printf("{");
    print_float(a.skintone_Hmin);
    print_float(a.skintone_Hmax);
    print_float(a.skintone_Ymin);
    print_float(a.skintone_Ymax);
    print_float(a.skintone_S_HY_min);
    print_float(a.skintone_S_HY_max);
    print_float(a.skintone_S_LY_min);
    print_float(a.skintone_S_LY_max);
    print_unsigned_char(a.skintone_percentage);
    printf("},\n");
}

void print_chromatix_MWB_type(chromatix_MWB_type a) {
    printf("{");
    print_chromatix_manual_white_balance_type(a.MWB_tl84);
    print_chromatix_manual_white_balance_type(a.MWB_d50);
    print_chromatix_manual_white_balance_type(a.MWB_A);
    print_chromatix_manual_white_balance_type(a.MWB_d65);
    print_chromatix_manual_white_balance_type(a.strobe_flash_white_balance);
    print_chromatix_manual_white_balance_type(a.led_flash_white_balance);
    printf("},\n");
}

void print_chromatix_ZSL_type(chromatix_ZSL_type a) {
    printf("{");
    print_unsigned_short(a.ZSL_default_shutter_lag);
    print_unsigned_short(a.ZSL_max_Q_factor_reduction);
    printf("},\n");
}

void print_chromatix_HDR_type(chromatix_HDR_type a) {
    printf("{");
    print_float(a.tolerance);
    print_float(a.contrast_meter);
    print_float(a.normal_lowlight_boost_meter);
    print_float(a.brightlight_boost_meter);
    printf("},\n");
}

void print_chromatix_face_detection_type(chromatix_face_detection_type a) {
    printf("{");
    print_int(a.minimum_face_width);
    print_int(a.maximum_face_width);
    print_int(a.maximum_num_face_to_detect);
    print_int(a.angles_to_detect_pose_front);
    print_int(a.angles_to_detect_pose_half_profile);
    print_int(a.angles_to_detect_pose_profile);
    printf("},\n");
}

void print_chromatix_face_recognition_type(chromatix_face_recognition_type a) {
    printf("{");
    print_int(a.max_num_users);
    print_int(a.max_data_per_user);
    printf("},\n");
}

void print_chroma_aliasing_correction_type(chroma_aliasing_correction_type a) {
    printf("{");
    print_int(a.correction_strength);
    print_unsigned_char(a.brightness_threshold);
    print_unsigned_char(a._threshold_center);
    print_unsigned_char(a.soft_threshold_span);
    printf("},\n");
}

void print_chromatix_chroma_aliasing_correction_type(chromatix_chroma_aliasing_correction_type a) {
    printf("{");
    print_tuning_control_type(a.control_CAC);
    print_trigger_point_type(a.CAC_lowlight_trigger);
    print_chroma_aliasing_correction_type(a.CAC_lowlight);
    print_chroma_aliasing_correction_type(a.CAC_normal);
    printf("},\n");
}

void print_chromatix_color_tint_correction_type(chromatix_color_tint_correction_type a) {
    printf("{");
    print_int(a.tint_correction_mode);
    print_unsigned_char(a.tint_correction_strength);
    print_unsigned_char(a.tint_correction_accuracy_degree);
    printf("},\n");
}

void print_chromatix_LTM_type(chromatix_LTM_type a) {
    printf("{");
    print_float(a.fCV_R);
    print_float(a.fCV_G);
    print_float(a.fCV_B);
    print_float(a.fCV_Kc);
    print_float(a.fCV_Cthr);
    print_int(a.nInitCntFactor);
    print_float(a.fSigmaXY);
    print_float(a.fSigmaZ);
    print_int(a.nNormalLoCut);
    print_int(a.nNormalHiCut);
    print_int(a.nStrongLoCut);
    print_int(a.nStrongHiCut);
    print_float(a.fBusyThr1);
    print_float(a.fBusyThr2);
    print_unsigned_long(a.nLowTrig0);
    print_unsigned_long(a.nLowTrig1);
    print_unsigned_long(a.nLowTrig2);
    print_unsigned_long(a.nLowTrig3);
    print_unsigned_long(a.nHighTrig0);
    print_unsigned_long(a.nHighTrig1);
    print_unsigned_long(a.nHighTrig2);
    print_unsigned_long(a.nHighTrig3);
    print_float(a.fManualGTMGain);
    print_float(a.fManualGTMSigma);
    print_float(a.fW1_LA);
    print_float(a.fScaleConstraintLB);
    print_float(a.fScaleSigmaMult);
    print_float(a.fScaleWidthLB);
    print_float(a.fMasterScaleAdj);
    print_float(a.fShiftSigma);
    print_float(a.fShiftMag);
    print_int(a.nSoftThr0);
    print_int(a.nSoftThr1);
    print_int(a.nSoftThrSlope);
    print_float(a.fShiftScaleAdj);
    printf("},\n");
}

void print_chromatix_post_processing_type(chromatix_post_processing_type a) {
    printf("{");
    print_chromatix_HDR_type(a.chromatix_HDR);
    print_chromatix_face_detection_type(a.chromatix_face_detection);
    print_chromatix_face_recognition_type(a.chromatix_face_recognition);
    print_chromatix_chroma_aliasing_correction_type(a.chromatix_chroma_aliasing_correction);
    print_chromatix_color_tint_correction_type(a.chromatix_color_tint_correction);
    print_chromatix_LTM_type(a.chromatix_LTM_data);
    printf("},\n");
}

void print_chromatix_VFE_type(chromatix_VFE_type a) {
    printf("{");
    print_chromatix_black_level_type(a.chromatix_black_level);
    print_chromatix_channel_balance_gains_type(a.chromatix_channel_balance_gains);
    print_chromatix_ABF2_type(a.chromatix_ABF2);
    print_chromatix_BPC_type(a.chromatix_BPC);
    print_chromatix_demosaic_type(a.chromatix_demosaic);
    print_chromatix_CL_filter_type(a.chromatix_CL_filter);
    print_chromatix_CC_type(a.chromatix_CC);
    print_chromatix_gamma_type(a.chromatix_gamma);
    print_chromatix_CV_type(a.chromatix_CV);
    print_chromatix_ASF_5x5_type(a.chromatix_ASF_5x5);
    print_chromatix_ASF_7x7_type(a.chromatix_ASF_7x7);
    print_chromatix_LA_type(a.chromatix_LA);
    print_chromatix_CS_MCE_type(a.chromatix_CS_MCE);
    print_chromatix_wavelet_type(a.chromatix_wavelet);
    print_chromatix_temporal_denoise_type(a.chromatix_temporal_denoise);
    print_chromatix_SCE_type(a.chromatix_SCE);
    print_chromatix_grid_stats_type(a.chromatix_grid_stats);
    print_chromatix_skin_detection_type(a.chromatix_skin_detection);
    printf("},\n");
}

void print_chromatix_parms_type(chromatix_parms_type a) {
    //printf("{");
    print_chromatix_version_type(a.chromatix_version);
    print_unsigned_char(a.is_compressed);
    print_unsigned_short(a.revision_number);
    print_chromatix_VFE_type(a.chromatix_VFE);
    print_chromatix_MWB_type(a.chromatix_MWB);
    print_AWB_algo_struct_type(a.AWB_algo_data);
    print_Bayer_AWB_parameters_type(a.AWB_bayer_algo_data);
    print_AEC_algo_struct_type(a.AEC_algo_data);
    print_chromatix_auto_flicker_detection_data_type(a.auto_flicker_detection_data);
    print_ASD_struct_type(a.ASD_algo_data);
    print_chromatix_ZSL_type(a.chromatix_ZSL);
    print_chromatix_post_processing_type(a.chromatix_post_processing);
    //printf("},\n");
}


void print_chromatix_linearization_type(chromatix_linearization_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < 8 ; i++) {
        print_unsigned_short(a.r_lut_p[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_unsigned_short(a.r_lut_base[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_float(a.r_lut_delta[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 8 ; i++) {
        print_unsigned_short(a.gr_lut_p[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_unsigned_short(a.gr_lut_base[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_float(a.gr_lut_delta[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 8 ; i++) {
        print_unsigned_short(a.gb_lut_p[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_unsigned_short(a.gb_lut_base[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_float(a.gb_lut_delta[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 8 ; i++) {
        print_unsigned_short(a.b_lut_p[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_unsigned_short(a.b_lut_base[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 9 ; i++) {
        print_float(a.b_lut_delta[i]);
    }
    printf("},");
    printf("},\n");
}

void print_mesh_rolloff_array_type(mesh_rolloff_array_type a) {
    printf("{");
    print_unsigned_short(a.mesh_rolloff_table_size);
    printf("{");
    for(int i = 0 ; i < MESH_ROLLOFF_SIZE ; i++) {
        print_float(a.r_gain[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < MESH_ROLLOFF_SIZE ; i++) {
        print_float(a.gr_gain[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < MESH_ROLLOFF_SIZE ; i++) {
        print_float(a.gb_gain[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < MESH_ROLLOFF_SIZE ; i++) {
        print_float(a.b_gain[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_L_type(chromatix_L_type a) {
    printf("{");
    print_tuning_control_type(a.control_linearization);
    print_trigger_point_type(a.linearization_lowlight_trigger);
    print_chromatix_CCT_trigger_type(a.linear_A_trigger);
    print_chromatix_CCT_trigger_type(a.linear_D65_trigger);
    print_chromatix_linearization_type(a.linear_table_A_lowlight);
    print_chromatix_linearization_type(a.linear_table_A_normal);
    print_chromatix_linearization_type(a.linear_table_TL84_lowlight);
    print_chromatix_linearization_type(a.linear_table_TL84_normal);
    print_chromatix_linearization_type(a.linear_table_Day_lowlight);
    print_chromatix_linearization_type(a.linear_table_Day_normal);
    printf("},\n");
}

void print_chromatix_rolloff_type(chromatix_rolloff_type a) {
    printf("{");
    print_tuning_control_type(a.control_rolloff);
    print_trigger_point_type(a.rolloff_lowlight_trigger);
    print_chromatix_CCT_trigger_type(a.rolloff_A_trigger);
    print_chromatix_CCT_trigger_type(a.rolloff_D65_trigger);
    print_float(a.rolloff_LED_start);
    print_float(a.rolloff_LED_end);
    print_float(a.rolloff_Strobe_start);
    print_float(a.rolloff_Strobe_end);
    printf("{");
    for(int i = 0 ; i < ROLLOFF_MAX_LIGHT ; i++) {
        print_mesh_rolloff_array_type(a.chromatix_mesh_rolloff_table[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ROLLOFF_MAX_LIGHT ; i++) {
        print_mesh_rolloff_array_type(a.chromatix_mesh_rolloff_table_lowlight[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < ROLLOFF_MAX_LIGHT ; i++) {
        print_mesh_rolloff_array_type(a.chromatix_mesh_rolloff_table_golden_module[i]);
    }
    printf("},");
    print_mesh_rolloff_array_type(a.chromatix_mesh_rolloff_table_LED);
    print_mesh_rolloff_array_type(a.chromatix_mesh_rolloff_table_Strobe);
    printf("},\n");
}

void print_chromatix_LA_special_effects_type(chromatix_LA_special_effects_type a) {
    printf("{");
    printf("{");
    for(int i = 0 ; i < 64 ; i++) {
        print_float(a.LA_LUT_backlit[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 64 ; i++) {
        print_float(a.LA_LUT_solarize[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 64 ; i++) {
        print_float(a.LA_LUT_posterize[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 64 ; i++) {
        print_float(a.LA_LUT_blackboard[i]);
    }
    printf("},");
    printf("{");
    for(int i = 0 ; i < 64 ; i++) {
        print_float(a.LA_LUT_whiteboard[i]);
    }
    printf("},");
    printf("},\n");
}

void print_chromatix_VFE_common_type(chromatix_VFE_common_type a) {
    //printf("{");
    print_chromatix_version_type(a.chromatix_version);
    print_unsigned_char(a.is_compressed);
    print_unsigned_short(a.revision_number);
    print_chromatix_L_type(a.chromatix_L);
    print_chromatix_rolloff_type(a.chromatix_rolloff);
    print_chromatix_LA_special_effects_type(a.chromatix_LA_special_effects);
    //printf("},\n");
}




#endif /* CHROMATIX_CHROMATIX_TEST_H_ */
