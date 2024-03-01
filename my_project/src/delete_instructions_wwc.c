#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

void deleteDirectoryRecursive(const char *path);


int main(int argc, char *argv[]) {
    char path[1024];
   // char cDrive[] = "C:\\";
    char cDrive[] = "/mnt/c/";
    //if nothing is pressed then clear the temp/////////////////////////////////////////////////////////////
    if (argv[1] == NULL){

    // char path[]="C:\\Windows\\Temp";
    //char path[]="C:/Windows/Temp";
    char path[]="/mnt/c/Windows/Temp";


    deleteDirectoryRecursive(path);

    return EXIT_SUCCESS;
    }

 // if temp is the input then clear the temp ///////////////////////////////////////////////////////////////////////////
    if (strcmp(argv[1], "temp") == 0){
    // char path[]="C:\\Windows\\Temp";
    //char path[]="C:/Windows/Temp";
    char path[]="/mnt/c/Windows/Temp";

    deleteDirectoryRecursive(path);

    return EXIT_SUCCESS;
    }

 // if dir is the input then clear the current directory, but don't clear anything from C except temp folder /////////////////////////////////////////////////////////////////
    if (strcmp(argv[1], "dir") == 0){
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!=NULL){

        if (strncmp(cwd, cDrive, strlen(cDrive)) == 0) {

            printf("Current working directory is in the C drive. Therefore, deleting temp only. \n");
            
            // char path[]="C:\\Windows\\Temp";
            //char path[]="C:/Windows/Temp";
            char path[]="/mnt/c/Windows/Temp";
            deleteDirectoryRecursive(path);

            return EXIT_SUCCESS;

        } else {

            printf("Current working directory is not in the C drive.\n");
            strcpy(path, cwd);
            
            deleteDirectoryRecursive(path);
            return EXIT_SUCCESS;
        }
        }
        //////////////directory path in input
    
    deleteDirectoryRecursive(argv[1]);

    return EXIT_SUCCESS;

    }

    deleteDirectoryRecursive(argv[1]);

    return EXIT_SUCCESS;

}