package com.kuailexs.printCamerapParameter;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main1 {
	
	public static void main(String[] args) throws IOException {
		List<String> distList = new ArrayList<>();
		
		FileReader fileReader1 = new FileReader("/work/LineageOS/vendor/xiaomi/cancro/cancro-vendor.mk");
		BufferedReader bf1 = new BufferedReader(fileReader1);
		String line = null;
		while (( line = bf1.readLine() ) != null) {
			line = line.trim();
			if(!"".equals(line) && !line.startsWith("#") && line.contains(":")) {
				String[] ddd = line.split(":");
				if(ddd.length == 2) {
					String dd2 = ddd[1];
					dd2 = dd2.trim();
					ddd = dd2.split("/");
					dd2 = ddd[ddd.length - 1];
					dd2 = dd2.trim();
					if(dd2.endsWith("\\")) {
						dd2 = dd2.substring(0,dd2.length() - 2);
						dd2 = dd2.trim();
					}
					if(dd2.endsWith(".so")) {
						dd2 = dd2.substring(0 , dd2.length() - 3);
					}
					distList.add(dd2);
				}
			}
		}
		
		Set<String> set = new HashSet<>();
		FileReader fileReader = new FileReader("/work/android_vendor_qcom_proprietary/log.txt");
		BufferedReader bf = new BufferedReader(fileReader);
		line = null;
		FileWriter fileWriter = new FileWriter("/work/android_vendor_qcom_proprietary/log1.txt");
		while (( line = bf.readLine() ) != null) {
			line = line.trim();
			if(!"".equals(line) ) {
				String[] ddd = line.split("LOCAL_MODULE");
				if(ddd.length == 2) {
					String dd2 = ddd[1];
					dd2 = dd2.trim();
					if(dd2.startsWith(":=")) {
						line = dd2.split(":=")[1].trim();
						set.add(line);
					}
				}
			}
		}
		List<String> list = new ArrayList<>(set);
		Collections.sort(list);
		fileWriter.write("# camera \n" + 
		"PRODUCT_PACKAGES += \\\n");
		for(String dist : list) {
			if(distList.contains(dist)) {
				fileWriter.write("    " + dist + " \\\n");
			}
		}
		fileWriter.write("\n\n# camera maybe not need \n" + 
				"PRODUCT_PACKAGES += \\\n");
		for(String dist : list) {
			if(!distList.contains(dist)) {
				fileWriter.write("    " + dist + " \\\n");
			}
		}
		fileWriter.write("\n\n\n");
		for(String dist : distList) {
			if(!list.contains(dist)) {
				fileWriter.write("    " + dist + "\n");
			}
		}
		fileWriter.flush();
		fileWriter.close();
	}

}
