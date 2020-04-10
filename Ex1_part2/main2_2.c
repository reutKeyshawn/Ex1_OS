#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

char child_stack[10000 + 1];

void print(const char *text)
{
	for (int i = 0; i < 5; i++)
	{
		printf("it's a %s", text);
	}
	sleep(10);
}

int child_thread(void *parm)
{
	print("child thread\n");
}

int main()
{
	int id1 = clone(child_thread, child_stack + 10000, CLONE_PARENT, 0);
	int id2 = clone(child_thread, child_stack + 10000, CLONE_PARENT, 0);
	printf("clone result:%d\n ", id1);
	printf("clone result:%d\n ", id2);

	return 0;
}