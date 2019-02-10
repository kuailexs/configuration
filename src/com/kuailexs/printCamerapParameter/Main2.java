package com.kuailexs.printCamerapParameter;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main2 {

	static String prepath = "/work/LineageOS/vendor/qcom/proprietary"
			+ "/mm-camera/mm-camera2/media-controller/modules/sensors"
			+ "/chromatix/0301/libchromatix";
	public static void main(String[] args) throws IOException {
		

		List<String> fileList =  new ArrayList<>();
		
		File rootDir = new File("/work/bb");
		if(!rootDir.exists()) {
			return;
		}
		if(!rootDir.isDirectory()) {
			return;
		}
		String[] files = rootDir.list();
		fileList.addAll(Arrays.asList(files));
		Collections.sort(fileList);
		String dirName1 = null;
		String dirName2 = null;
		String android_mk1 = "ifeq ($(call is-vendor-board-platform,QCOM),true)\n" + 
							"include $(call all-subdir-makefiles)\n" + 
							"endif";
		
		for (String filename : fileList) {
			if(filename.contains("_common.h")) {
				System.out.println(filename);
				dirName1 = filename.substring(filename.indexOf("_")+1, filename.lastIndexOf("_"));
				//
				File dir1  = new File(prepath + "/chromatix_"+ dirName1);
				dir1.mkdirs();
				File fileandroid_mk1  = new File(prepath + "/chromatix_"+ dirName1+"/Android.mk");
				fileandroid_mk1.createNewFile();
				FileOutputStream fops = new FileOutputStream(fileandroid_mk1);
				fops.write(android_mk1.getBytes());
				fops.flush();
				fops.close();
			}
			dirName2 = filename.split(dirName1)[1];
			dirName2 =dirName2.substring(1, dirName2.length()-2);
			System.out.println(dirName1);
			System.out.println(dirName2);
			//
			File dir2  = new File(prepath + "/chromatix_"+ dirName1 + "/" + dirName2);
			dir2.mkdirs();
			//copy .h
			String sou = "/work/bb/" + filename;
			String dist = prepath + "/chromatix_"+ dirName1 + "/" + dirName2 + "/" + filename;
			copyfile( sou,  dist) ;
			
			String android_mk2 ="" + 
					dirName1.toUpperCase() + "_CHROMATIX_" + 
					dirName2.toUpperCase() + "_PATH := $(call my-dir)\n" + 
					"\n" + 
					"# ---------------------------------------------------------------------------\n" + 
					"#                      Make the shared library (libchromatix_" + dirName1 + "_" + dirName2 + ")\n" + 
					"# ---------------------------------------------------------------------------\n" + 
					"\n" + 
					"include $(CLEAR_VARS)\n" + 
					"LOCAL_PATH := $("+dirName1.toUpperCase()+"_CHROMATIX_"+dirName2.toUpperCase()+"_PATH)\n" + 
					"LOCAL_MODULE_TAGS := optional\n" + 
					"\n" + 
					"LOCAL_CFLAGS:= -DAMSS_VERSION=$(AMSS_VERSION) \\\n" + 
					"        $(mmcamera_debug_defines) \\\n" + 
					"        $(mmcamera_debug_cflags) \\\n" + 
					"        -include camera_defs_i.h\n" + 
					"\n" + 
					"LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../../\n" + 
					"LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../../../../../../common/\n" + 
					"LOCAL_C_INCLUDES += "+filename+"\n" + 
					"\n" + 
					"LOCAL_SRC_FILES:= chromatix_"+dirName1+"_"+dirName2+".c\n" + 
					"\n" + 
					"LOCAL_MODULE           := libchromatix_"+dirName1+"_"+dirName2+"\n" + 
					"LOCAL_SHARED_LIBRARIES := libcutils\n" + 
					"include $(LOCAL_PATH)/../../../../../../../../../local_additional_dependency.mk\n" + 
					"\n" + 
					"ifeq ($(MM_DEBUG),true)\n" + 
					"LOCAL_SHARED_LIBRARIES += liblog\n" + 
					"endif\n" + 
					"LOCAL_MODULE_OWNER := qti\n" + 
					"LOCAL_PROPRIETARY_MODULE := true\n" + 
					"\n" + 
					"include $(BUILD_SHARED_LIBRARY)";
			File fileandroid_mk2  = new File(prepath + "/chromatix_"+ dirName1 + "/" + dirName2 +"/Android.mk");
			fileandroid_mk2.createNewFile();
			FileOutputStream fops = new FileOutputStream(fileandroid_mk2);
			fops.write(android_mk2.getBytes());
			fops.flush();
			fops.close();
			
			String file_c_String = "";
			if("common".equals(dirName2)) {
				//
				file_c_String = "" + 
						"/*============================================================================\n" + 
						"\n" + 
						"  Copyright (c) 2014 Qualcomm Technologies, Inc. All Rights Reserved.\n" + 
						"  Qualcomm Technologies Proprietary and Confidential.\n" + 
						"\n" + 
						"============================================================================*/\n" + 
						"\n" + 
						"/*============================================================================\n" + 
						" *                      INCLUDE FILES\n" + 
						" *===========================================================================*/\n" + 
						"#include \"chromatix_common.h\"\n" + 
						"#include \"camera_dbg.h\"\n" + 
						"\n" + 
						"static chromatix_VFE_common_type chromatix_"+dirName1+"_parms = {\n" + 
						"#include \""+filename+"\"\n" + 
						"};\n" + 
						"\n" + 
						"/*============================================================================\n" + 
						" * FUNCTION    - load_chromatix -\n" + 
						" *\n" + 
						" * DESCRIPTION:\n" + 
						" *==========================================================================*/\n" + 
						"void *load_chromatix(void)\n" + 
						"{\n" + 
						"  CDBG(\"%s:%d%d\\n\", __func__, __LINE__);\n" + 
						"  return &chromatix_"+dirName1+"_parms;\n" + 
						"}";
			}else {
				file_c_String = "" + 
						"/*============================================================================\n" + 
						"\n" + 
						"  Copyright (c) 2014 Qualcomm Technologies, Inc. All Rights Reserved.\n" + 
						"  Qualcomm Technologies Proprietary and Confidential.\n" + 
						"\n" + 
						"============================================================================*/\n" + 
						"\n" + 
						"/*============================================================================\n" + 
						" *                      INCLUDE FILES\n" + 
						" *===========================================================================*/\n" + 
						"#include \"chromatix.h\"\n" + 
						"#include \"sensor_dbg.h\"\n" + 
						"\n" + 
						"static chromatix_parms_type chromatix_"+dirName1+"_parms = {\n" + 
						"#include \""+filename+"\"\n" + 
						"};\n" + 
						"\n" + 
						"/*============================================================================\n" + 
						" * FUNCTION    - load_chromatix -\n" + 
						" *\n" + 
						" * DESCRIPTION:\n" + 
						" *==========================================================================*/\n" + 
						"void *load_chromatix(void)\n" + 
						"{\n" + 
						"  SLOW(\"chromatix ptr %p\", &chromatix_"+dirName1+"_parms);\n" + 
						"  return &chromatix_"+dirName1+"_parms;\n" + 
						"}";
			}
			// .c 
			File file_c  = new File(prepath + "/chromatix_"+ dirName1 + "/" + dirName2 +"/chromatix_"+dirName1+"_"+dirName2+".c");
			file_c.createNewFile();
			FileOutputStream fopsfile_c = new FileOutputStream(file_c);
			fopsfile_c.write(file_c_String.getBytes());
			fopsfile_c.flush();
			fopsfile_c.close();
		}
	}
	static void copyfile(String sou, String dist) throws IOException {
		FileInputStream fips = new FileInputStream(sou);
		File distFile  = new File(dist);
		distFile.createNewFile();
		FileOutputStream fops = new FileOutputStream(distFile);
		int len = 0;
		byte[] bytes = new byte[1024];
		while ((len  = fips.read(bytes)) > 0) {
			fops.write(bytes,0, len);
		}
		
		fops.flush();
		fops.close();
	}
}

