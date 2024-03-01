#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

// a function deleteDirectoryRecursive has been created to delete files and folder recursively.

void deleteDirectoryRecursive(const char *path) {
   
    DIR *dir;
    struct dirent *entry;
    char fullPath[1024];

    // Open the directory
    
    dir = opendir(path);


    if (dir == NULL) {
        printf("Unable to open directory: %s\n", path);
        exit(EXIT_FAILURE);
    }
    

    // Iterate through each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue; // Skip '.' and '..' directories

        // Construct full path for the entry
        snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

        if (entry ->d_type == DT_DIR){
            deleteDirectoryRecursive(fullPath);

            
            if (rmdir(fullPath) == 0) {
            printf("deleted: %s\n", fullPath);
            } 

        } else{

            
            if (remove(fullPath) == 0) {
            printf("deleted: %s\n", fullPath);
            } 
        }

    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    char path[1024];
    char cDrive[] = "C:\\";
    
    //if nothing is pressed then clear the temp/////////////////////////////////////////////////////////////
    if (argv[1] == NULL){

    char path[]="C:\\Windows\\Temp";


    deleteDirectoryRecursive(path);

    return EXIT_SUCCESS;
    }

 // if temp is the input then clear the temp ///////////////////////////////////////////////////////////////////////////
    if (strcmp(argv[1], "temp") == 0){
    char path[]="C:\\Windows\\Temp";

    deleteDirectoryRecursive(path);

    return EXIT_SUCCESS;
    }

 // if dir is the input then clear the current directory, but don't clear anything from C except temp folder /////////////////////////////////////////////////////////////////
    if (strcmp(argv[1], "dir") == 0){
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!=NULL){

        if (strncmp(cwd, cDrive, strlen(cDrive)) == 0) {

            printf("Current working directory is in the C drive. Therefore, deleting temp only. \n");
            
            char path[]="C:\\Windows\\Temp";
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

