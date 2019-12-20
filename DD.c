#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int C3, index;
	int D = getpid();
	char *arg[1] = {0};
	char *name;
	name = getlogin();

	C3 = fork();
	if (C3 == 0)
	{
		execv("CC", arg);
	}
	else
	{

		printf("Pid %d Code DD: Create process Pid %d (code CC) and waiting for 0.5 sec\n", D, C3);
		sleep(5);
		index = fork();


		if (index == 0)
		{
			write(1, "----output from ps-----\n", 25);
			execl("/bin/ps", "ps", "-u", "--forest", name , NULL);

			exit(5);
		}
		else
		{
			printf("Pid %d Code DD: 0.5 sec elapsed. Create %d (ps), and waiting for it to terminate.\n", D, index);
			int z;
			waitpid(index, &z, 0); // wait for ps tp be over

			printf("Pid %d Code DD: Process Pid %d terminate.\n", D, index);
			printf("Pid %d Code DD: Killing Process Pid %d.\n", D, C3);

			kill(C3, SIGKILL);
			printf("Pid %d Code DD: Process Pid %d terminate.\n", D, C3);
		}
	}

	exit(0);
}