#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//Find occanrace of the key word in a file
int contains(char* test, char* fileName){
    FILE *file = fopen(fileName, "r");
    int x = 0;
    char buffer[1024];
    if(file){
        while(fgets(buffer, 1024, file) != NULL){
            if(strstr(buffer, test) != NULL){
                x++;
            }
        }
    } else {
        x = 255;
    }
    fclose(file);
    if(x > 255 || x < 0)
        return 255;
    else
        return x;
}

int main(int argc, char *argv[]){
    char *keyword = argv[1];


    for(int i=0; i < (argc - 1); i++){
        int z = contains(keyword, argv[i + 2]);
        printf("the return value is %d\n", z);

    }
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