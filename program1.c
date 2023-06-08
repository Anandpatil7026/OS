#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t pid;
    int status;
    pid=fork();
    if (pid<0){
        printf("error:fork() failed.\n");
        return 1;
    }else if(pid==0){
        printf("this is the child processs with PId:%d\n", getpid());
        
        printf("parent proecss PID:%d\n",getpid());
        
        execlp("/bin/ls","ls",NULL);
        printf(" this should not be printed if exec() issuccefual.\n ");
        return 0;
    }
    else {
        printf("this is the parent processs with PId:%d\n", getpid());
        printf("parent proecss PID:%d\n",pid);
        
        wait(&status);
        printf(" child process exited with status:%d\n",status);
        return 0;
        
    }
    
}
