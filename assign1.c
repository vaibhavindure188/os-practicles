#include <stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
    int fd[2];
    char buffer[100];
    pipe(fd);

    pid_t p = fork();

    if(p < 0) cout<<"unsuccess"<<endl;
    else if(p > 0){
        close(fd[0]);
        write(fd[1],"message",10);
        wait(NULL);
    }
    else{
        close(fd[1]);
        int n = read(fd[0],buffer,100); // this line could be optional
        write(1,buffer,n);
    }
    
}