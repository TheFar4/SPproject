#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int A = getpid();
	int B, C1, C1a, D, C2, E, F;
	char *arg[1] = {0};
	B = fork();
	if (B == 0)
	{
		execv("BB", arg);
	}
	else
	{
		C1 = fork();
		if (C1 == 0)
		{
			execv("CC", arg);
		}
		else
		{
			C1a = fork();
			if (C1a == 0)
			{
				execv("CC", arg);
			}
			else
			{

				printf("\nPid %d, Code AA: Created process Pid %d(code BB), process Pid %d(code CC) and process Pid %d(code CC)\n", A, B, C1, C1a);

				wait(NULL); // wait for any child to finish

				printf("Pid %d Code AA: Process Pid %d terminated\n", A, B);

				C2 = fork();
				if (C2 == 0)
				{
					execv("CC", arg);
				}
				else
				{
					E = fork();
					if (E == 0)
					{
						execv("EE", arg);
					}
					else
					{
						int u;
						waitpid(E, &u, 0); // wait for ps tp be over
						D = fork();
						if (D == 0)
						{
							execv("DD", arg);
							exit(5);
						}
						else
						{
							printf("Pid %d Code AA: Created process Pid %d(code DD), process Pid %d(code CC), process Pid %d(code EE)\n", A, D, C2, E);
							int z;
							printf("Pid %d Code AA: Process Pid %d terminated(not D process) process.\n", A, E);
							waitpid(D, &z, 0); // wait fopr DD to terminate

							printf("Pid %d Code AA: Killing process Pid %d, 		Killing process Pid %d and 		Killing process Pid %d \n", A, C1, C1a, C2);
							kill(C1, SIGKILL);
							kill(C1a, SIGKILL);
							kill(C2, SIGKILL);

							sleep(0.25);

							printf("Pid %d Code AA: 0.25 sec elapsed\n", A);

							int xyzInteger;
							char string[200];
							
							printf("Pid %d Code AA: Input a string: ", A);
							scanf("%[^\n]%*c", string);

							printf("Pid %d Code AA: Input an interger: ", A);
							scanf("%d", &xyzInteger);



							F = fork();
							if (F == 0)
							{
								char buffer[10];
								snprintf(buffer, 10, "%d", xyzInteger);
								execlp("./FF", "./FF", string, buffer, "59404 and the group", NULL);
							}
							else
							{
								sleep(3);
								exit(0);
							}
						}
					}
				}
			}
		}
	}
}
