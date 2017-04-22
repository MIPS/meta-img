#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>

int main(void)
{
	printf("Welcome to UIO test prog\n");

	int fd = open("/dev/uio0", O_RDWR);
	void *memory;
	int *memory_int;
	int N = 1; //get one page.
	int offset = N * getpagesize();

	printf("Opening file /dev/uio0 \n");

	if (fd < 1) {
		printf("could not open /dev/uio0\n");
		exit(EXIT_FAILURE);
	}

	printf("Trying to mmap memory\n");

	memory = mmap(NULL, offset, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	if(memory == MAP_FAILED) {
		printf("couldn't mmap memory space\n");
		exit(EXIT_FAILURE);
	}

	memory_int = (unsigned int *) memory;

	printf("Writing 0xf at location 0x10C0_0004. 4 LEDs will light up. \n");

	(memory_int[1])  = 0xf;	//write 0xf to memory at location 0x10C0_0004.

	printf("Writing 0xf0 at location 0x10C0_0008. Bit 7:5 will be set as input. These switches will be read. \n");

	(memory_int[2])  = 0xf0; //write 0xf0 to memory at location 0x10C0_0000.

	printf("Reading 0x10C0_0000 for switches %08x \n", memory_int[0]);

	close(fd);
	exit(EXIT_SUCCESS);
}
