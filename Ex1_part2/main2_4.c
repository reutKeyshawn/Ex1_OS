
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
int main()
{

	pid_t b1 = fork();
	if (b1 == 0)
	{
		printf("\nb1 Number of Id: %d\n", getpid());
		printf("main2_1:\n\n");

		char *args[] = {"./main2_1", NULL};
		execvp(args[0], args); //run nested processes
	}
	else
	{
		sleep(5);
	}
	pid_t b2 = fork();
	if (b2 == 0)
	{
		printf("\nb2 Number of Id: %d\n", getpid());
		printf("main2_2:\n\n");

		char *args[] = {"./main2_2", NULL};
		execvp(args[0], args); //run clone processes
	}
	else
	{
		sleep(5);
	}
	pid_t b3 = fork();
	if (b3 == 0)
	{
		printf("\nb3 Number of Id: %d\n", getpid());
		printf("main2_3:\n\n");

		char *args[] = {"./main2_3", NULL};
		execvp(args[0], args); //run deamon process
	}
	else
	{
		sleep(5);
	}

	return 0;
}