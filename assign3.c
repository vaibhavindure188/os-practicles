#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
int fd[2],n;          //file descriptors for read[0] and write[1]
char buffer[100];   //no. of characters the child process read
 pid_t p;
            //process identifier and process
pipe(fd);          // fd= name of the pipe
p=fork();           //child process creation
if(p>0)
{
close(fd[0]);
printf("passing value to child");
write(fd[1],"hello my child\n", 15);
wait(NULL);

}
else
{
close(fd[1]);
n=read(fd[0],buffer,100);
write(1,buffer,n);    
}
}

