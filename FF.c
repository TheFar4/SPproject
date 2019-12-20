#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int F = getpid(); // get the process id for this function

	printf("Pid %d Code FF: \n", F); // display process id

	//display all arguments recieved sequentially
	for (int i = 1; i < 4; i++)
	{
		printf("argument %d %s	\n", i, argv[i]);
	}
	exit(0);
}