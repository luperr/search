#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//Find occanrace of the key word in a file
int numMatches(char* test, FILE *file){
    int x = 0;
    char buffer[1024];
    while(fgets(buffer, 1024, file) != NULL){
        if(strstr(buffer, test) != NULL){
            x++;
        }
    }
    if(x > 255)
        return 255;
    else
        return x;
}

int main(int argc, char *argv[]){

    FILE *file = fopen("file0.txt", "r");


    fclose(file);
    //Declaring all the varibles
    //What is pid_t????
   /*
    int x, status;
    pid_t child;
    x = 0;
    child = fork();

    //While??
    if(child){
        //Do the parent stuff
        if(-1 == wait(&status)){
            //do the thing after all the child processes are done
            printf("No child process to wait for\n");
        } else if(WIFEXITED(status)){
            //handle exit statuses here with WEXITSTATUS(status);
            printf("Child exit status\n"); 
        } else {
            //sweet sweet edge case of thread fuckerery
            printf("shit got fucked\n");
        }
    } else {
        //Do the child stuff
        printf("here is the child process running\n");
    }
    */
    printf("shit son it all worked!\n");

    return 0;
}