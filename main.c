#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//Does the file contain the key word?
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
    int status, x;
    pid_t child;

    if(argc == 1){
        printf("No arguments entered: please enter a keyword first followed by the files you want to search\n");
        exit(0);
    } else if(argc == 2){
        printf("No files selected: Please enter the files to search after the keyword\n");
        exit(0);
    }
    
    for(int i=2; i < argc ; i++){
    child = fork();
    if(child){
        //Do the parent stuff
        if(-1 == wait(&status)){
            //do the thing after all the child processes are done
            printf("No child process to wait for\n");
        } else if(WIFEXITED(status)){
            //handle exit statuses here with WEXITSTATUS(status);
        } else {
            //sweet sweet edge case of thread fuckerery
            printf("shit got fucked\n");
        }
    } else {
        int z = contains(keyword, argv[i]);
        if(z > 0 && z < 255){
            printf("%s\n", argv[i]);
        }
        exit(0);
        }
    }
    return 0;
}