#include "chromatix.h"
#include <dlfcn.h>
#include <stdio.h>

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
	printf("bb->chromatix_version:%hx:\n", bb->chromatix_version);
	printf("bb->is_compressed:%hd:\n", bb->is_compressed);
	printf("bb->revision_number:%hd:\n", bb->revision_number);

	printf("bb->chromatix_VFE:\n");

	chromatix_VFE_type vfe_type = bb->chromatix_VFE;
	printf("gain_start:%f:\n",
			vfe_type.chromatix_black_level.blk_lowlight_trigger.gain_start);
	printf("gain_end:%f:\n",
			vfe_type.chromatix_black_level.blk_lowlight_trigger.gain_end);
	printf("lux_index_start:%ld:\n",
			vfe_type.chromatix_black_level.blk_lowlight_trigger.lux_index_start);
	printf("lux_index_end:%ld:\n",
			vfe_type.chromatix_black_level.blk_lowlight_trigger.lux_index_end);

	dlclose(chromatix_handle);

	return 0;
}