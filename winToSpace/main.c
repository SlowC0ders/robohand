#include "wintospace.h"
#define INVALID_ARGUMENTS 1
int main(int argc, char *argv[]) {
	if (argc != 6) {
		printf("invalid number of arguments");
		return INVALID_ARGUMENTS;
	}
	if (strcmp(argv[1], "-i")) {
		printf("invalid key #1");
		return INVALID_ARGUMENTS;
	}
	if (strcmp(argv[3], "-o")) {
		printf("invalid key #2");
		return INVALID_ARGUMENTS;
	}

	if (strcmp(argv[5], "-wintospace")) {
		printf("invalid key #3");
		return INVALID_ARGUMENTS;
	}
	read(argv[2],argv[4]);
	return 0;
}