#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>

int main()
{

	__pid_t pid = fork(); //create child

	if (pid == 0)
	{

		chdir("/"); //move to root dir

		setsid(); //move to different session

		printf("starting deamon\n");

		/*close IO channels*/
		close(stdout);
		close(stdin);
		close(stderr);

		/*log showing daemon working*/
		openlog("deamon", LOG_PID, LOG_DAEMON);
		syslog(LOG_NOTICE, "daemon started\n");
		usleep(3000000);
		syslog(LOG_NOTICE, "daemon is doing something..\n");
		usleep(3000000);
		syslog(LOG_NOTICE, "daemon finished\n");
	}
	else
	{ //if fork didnt work
		printf("daemon PID %d\n", pid);
	}

	return 0;
}
