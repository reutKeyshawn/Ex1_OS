
#include <stdio.h>
#include <unistd.h>

int main()

{
    __pid_t process1 = fork();

    if (process1 == 0)
    {
        __pid_t process2 = fork();
        if (process2 == 0)
        {
            printf("\nHello you are in process 2, process number: %d\n" , getpid());
        }
        else
        {
            printf("\nHello you are in process 1, process number: %d\n" , getpid());
        }
    }
    else{
        printf("\nThis is the app, process number: %d\n" , getpid());
}
    return 0;
}
