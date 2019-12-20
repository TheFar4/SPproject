#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int fpXYZ;
	int E = getpid();

	fpXYZ = open("XYZ.txt", 0);
	printf("Pid %d Code EE: This is what I have read from XYZ.txt:\n", E);
	char c;

	while (read(fpXYZ, &c, 1) == 1) // while there is more characters in the file
	{
		write(1, &c, 1); // print to screen
	}

	write(1, "\n", 1); // print newline after EOF

	close(fpXYZ);
	printf("Pid %d Code EE: Deleted XYZ.txt and I am terminating\n", E);
	unlink("XYZ.txt");
	exit(0);
}