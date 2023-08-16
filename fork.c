#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    int status;
    pid=fork();
    if(pid<0)
    {
        printf("Error:fork() failed\n");
        return 1;
    }else if(pid==0){
        
        printf("this is the child process with pid %d\n",getpid());
        printf("this is the parent process pid %d\n",getpid());
        execlp("/bin/ls","ls",NULL)
            printf("this should not be printed if execlp() is successful \n");
        return 0;
    }
else {
    printf("this is the parent process pid %d \n",getpid());
