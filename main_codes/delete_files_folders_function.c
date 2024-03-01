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