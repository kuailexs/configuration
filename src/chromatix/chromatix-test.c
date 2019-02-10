#include "chromatix_common.h"
#include <dlfcn.h>
#include <stdio.h>
#include <string.h>

#include "chromatix-test.h"

int main(int argc, char **argv) {
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			void* chromatix_handle = dlopen(argv[i],
			RTLD_NOW);
			if (chromatix_handle == NULL) {
				printf("ERROR:%s:dlopen\n", dlerror());
				return -1;
			}
			if (strstr(argv[i],"_common") == NULL) {

				chromatix_parms_type* (*open_lib)() = (chromatix_parms_type* (*)())dlsym(chromatix_handle, "load_chromatix");

				if (open_lib == NULL) {
					printf("ERROR:%s:dlsym\n", dlerror());
					return -1;
				}

				chromatix_parms_type * bb = open_lib();
				print_chromatix_parms_type(*bb);

			} else {
				chromatix_VFE_common_type* (*open_lib)() = (chromatix_VFE_common_type* (*)())dlsym(chromatix_handle, "load_chromatix");
				if (open_lib == NULL) {
					printf("ERROR:%s:dlsym\n", dlerror());
					return -1;
				}

				chromatix_VFE_common_type * bb = open_lib();
				print_chromatix_VFE_common_type(*bb);
			}
			dlclose(chromatix_handle);
		}
	}
	return 0;
}
