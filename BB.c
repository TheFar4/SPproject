#include <stdio.h>
#define PERMS 0777
#include <sys/types.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int B = getpid();
	printf("Pid %d Code BB: Creating file XYZ.txt and write data to the file\n", B);

	int fpxyz;

	fpxyz = creat("XYZ.txt", PERMS);
	if (fpxyz < 0)
	{
		printf("Create XYZ error!");
		exit(0);
	}

	if (write(fpxyz, "Great!!! I'm learning process management....", 45) < 0)
	{
		printf("Write XYZ error!");
		exit(0);
	}

	close(fpxyz);
	printf("Pid %d Code BB: Done and terminating.\n", B);
	exit(0);
}
