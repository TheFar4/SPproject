#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int C = getpid();
	printf("Pid %d Code CC: Entering an infinite loop\n", C);
	while(1){
		usleep(100);
	}
	exit(0);
}