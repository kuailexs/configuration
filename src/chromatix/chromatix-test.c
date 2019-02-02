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
	print_chromatix_parms_type(*bb);

	dlclose(chromatix_handle);

	return 0;
}
