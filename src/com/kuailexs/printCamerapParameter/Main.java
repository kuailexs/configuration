package com.kuailexs.printCamerapParameter;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

	static Map<String, String> define = new HashMap<>();
	static StringBuffer sb = new StringBuffer();
	static List<String> listLine = new ArrayList<>();

	public static void main(String[] args) throws IOException {
		String chromatix_h_Path = "C:/Users/dhl/workspace/chromatix/src/chromatix/chromatix.h";

		BufferedReader br = new BufferedReader(new FileReader(chromatix_h_Path));
		List<String> list = bufferedReaderToStringList(br);
		for (String line : list) {
			sb.append(line + "\n");
		}

		String lines = sb.toString();
		Pattern pattern2 = Pattern.compile("/\\*(.*?)\\*/", Pattern.DOTALL);
		Matcher matcher2 = pattern2.matcher(lines);
		lines = matcher2.replaceAll("");

		StringReader sr = new StringReader(lines);
		br = new BufferedReader(sr);
		list = bufferedReaderToStringList(br);
		// sb = new StringBuffer();
		for (String line : list) {
			line = line.replaceAll("\t", " ");
			line = deletespace(line);
			listLine.add(line);
		}
		// 一个结构体的所有行
		List<String> oneStruct = new ArrayList<>();
		boolean isOneEnd = false;
		Iterator<String> it = listLine.iterator();

		while (it.hasNext()) {
			String line = it.next();
			if (isOneEnd) {
				dealOneStruct(oneStruct);
				isOneEnd = false;
				oneStruct = new ArrayList<>();
			}
			if (line.startsWith("#ifndef") || line.startsWith("#define") || line.startsWith("#endif")) {
				continue;
			}
			while (line.trim().endsWith("\\")) {
				if (it.hasNext()) {
					line = line.substring(0, line.lastIndexOf("\\")) + it.next();
				}
			}
			line = line.trim();
			if (line.startsWith("typedef") && !line.contains("{") && !line.contains("}") && line.endsWith(";")) {
				oneStruct.add(line);
				isOneEnd = true;
				continue;
			}
			while (line.contains("}") && !line.contains(";")) {
				if (it.hasNext()) {
					line = line + it.next();
				}
			}
			oneStruct.add(line);
			if (line.contains("}") && line.contains(";")) {
				isOneEnd = true;
			}
		}
		if (isOneEnd) {
			dealOneStruct(oneStruct);
			isOneEnd = false;
			oneStruct = new ArrayList<>();
		}
		System.out.println();

	}

	private static void dealOneStruct(List<String> oneStruct) {
		if (oneStruct == null || oneStruct.size() < 1) {
			return;
		}
		String oneStructLine = "";
		if (oneStruct.size() > 1) {
			for (String line : oneStruct) {
				oneStructLine += line;
			}
		} else {
			oneStructLine = oneStruct.get(0);
		}
		oneStructLine = deletespace(oneStructLine);
		oneStructLine = oneStructLine.replace(" [", "[");
		oneStructLine = oneStructLine.replace(" ]", "]");
		oneStructLine = oneStructLine.replace(" {", "{");
		oneStructLine = oneStructLine.replace(" }", "}");
		oneStructLine = oneStructLine.replace("[ ", "[");
		oneStructLine = oneStructLine.replace("] ", "]");
		oneStructLine = oneStructLine.replace("{ ", "{");
		oneStructLine = oneStructLine.replace("} ", "}");
		if (oneStructLine.startsWith("typedef enum")) {
			return;// 枚举不处理
		}

		// System.out.println(oneStructLine);

		if (!oneStructLine.contains("{")) {
			// 单个类型别名
			String name = oneStructLine.substring(oneStructLine.lastIndexOf(" "));
			if (name.contains(";")) {
				name = name.substring(0, name.indexOf(";")).trim();
			}
			String type = oneStructLine.substring(oneStructLine.indexOf(" "), oneStructLine.lastIndexOf(" ")).trim();

			String printStr = "void print_" + name + "(" + name + " a) {\n";
			printStr = printStr + "    print_" + type.replace(" ", "_") + "(a);\n";
			printStr = printStr + "}\n";

			System.out.println(printStr);

		} else {
			// 结构体
			String name = oneStructLine.substring(oneStructLine.indexOf("}") + 1);
			if (name.contains(";")) {
				name = name.substring(0, name.indexOf(";")).trim();
			}
			String zhongjian = oneStructLine.substring(oneStructLine.indexOf("{") + 1, oneStructLine.indexOf("}"));
			String[] childs = zhongjian.split(";");
			String printStr = "void print_" + name + "(" + name + " a) {\n";

			printStr = printStr + "    printf(\"{\");\n";
			for (String child : childs) {
				if (hasTxt(child)) {
					child = child.trim();
					String childName = child.substring(child.lastIndexOf(" ")).trim();
					String childType = child.substring(0, child.lastIndexOf(" ")).trim();
					if (childName.contains(",")) {
						//a,b,c,d,e,f
						String[] childNames = childName.split(",");
						for(int i = 0 ; i < childNames.length ; i++) {
							printStr = printStr + "    print_" + childType.replace(" ", "_") + "(a." + childNames[i] + ");\n";
						}
					} else if (childName.contains("[")) {
						// setting[ASF_MAX_LIGHT]
						childName = childName.substring(0, childName.length() - 1);
						// setting[ASF_MAX_LIGHT
						childName = childName.replace("][", ",");
						childName = childName.replace("[", ";");
						String childName_Name = childName.split(";")[0];
						String[] childNameMaxs = childName.split(";")[1].split(",");
						if (childNameMaxs.length == 1) {
							printStr = printStr + "    printf(\"{\");\n";
							printStr = printStr + "    for(int i = 0 ; i < " + childNameMaxs[0] + " ; i++) {\n";
							printStr = printStr + "        print_" + childType.replace(" ", "_") + "(a." + childName_Name
									+ "[i]);\n";
							printStr = printStr + "    }\n";
							printStr = printStr + "    printf(\"},\");\n";
						} else if (childNameMaxs.length == 2) {
							printStr = printStr + "    printf(\"{\");\n";
							printStr = printStr + "    for(int i = 0 ; i < " + childNameMaxs[0] + " ; i++) {\n";
							
							printStr = printStr + "        printf(\"{\");\n";
							printStr = printStr + "        for(int j = 0 ; j < " + childNameMaxs[1] + " ; j++) {\n";
							
							printStr = printStr + "            print_" + childType.replace(" ", "_") + "(a." + childName_Name
									+ "[i][j]);\n";
							printStr = printStr + "        }\n";
							printStr = printStr + "        printf(\"},\");\n";
							
							printStr = printStr + "    }\n";
							printStr = printStr + "    printf(\"},\");\n";
							
						}else {
							System.out.println("错误！");
						}
					} else {
						printStr = printStr + "    print_" + childType.replace(" ", "_") + "(a." + childName + ");\n";
					}
				}
			}
			printStr = printStr + "    printf(\"},\\n\");\n";
			printStr = printStr + "}\n";
			System.out.println(printStr);
		}

	}

	/**
	 * 删除多余空格
	 * 
	 * @param line
	 * @return
	 */
	private static String deletespace(String line) {
		StringBuffer sb = new StringBuffer();// 用其他方法实现
		int flag;
		for (int i = 0; i < line.length(); i++) {
			flag = 0;
			if (line.charAt(i) != ' ') {
				sb.append(line.charAt(i));
			} else {
				flag = 1;
			}
			try {
				if (line.charAt(i) == ' ' && line.charAt(i + 1) != ' ') {
					sb.append(' ');
				}
			} catch (Exception e) {
				continue;
			}
		}
		return sb.toString();
	}

	private static List<String> bufferedReaderToStringList(BufferedReader br) throws IOException {
		List<String> list = new ArrayList<>();
		String line = null;
		while ((line = br.readLine()) != null) {
			line = line.trim();
			if (!hasTxt(line)) {
				continue;
			}
			if (line.startsWith("//")) {
				continue;
			}
			if ("#ifndef CHROMATIX_H".equals(line) || "#define CHROMATIX_H".equals(line) || "#endif".equals(line)) {
				continue;
			}
			if (line.contains("//")) {
				String[] lineArray = line.split("//");
				line = lineArray[0].trim();
				if (!hasTxt(line)) {
					continue;
				}
			}

			list.add(line);

		}
		return list;
	}

	private static boolean hasTxt(String line) {
		if (line == null || "".equals(line.trim()))
			return false;
		return true;
	}

}
