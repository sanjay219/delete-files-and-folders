# Compiler
CC = gcc

# Compiler flags
CFLAGS = -fPIC

#directory containing the main codes
current_DIR = $(shell pwd)
//current_DIR = $(cd)
MainCode_DIR = $(current_DIR)/main_codes

#default project name
project_name := my_project

all: folders new1 new2 copy_file clean copy_again

folders:
 # mkdir -p $(project_name)/src $(project_name)/bin $(project_name)/include $(project_name)/lib
 # above instruction will create three folders src, bin, include and lib inside the project_name folder
	mkdir -p $(project_name)/src $(project_name)/bin $(project_name)/include $(project_name)/lib
 # two extra folders are needed inside the lib to store object files and shared object files.
	cd $(project_name)/lib && mkdir -p Object_files sharedObject_files 
 # above instruction will create two folders Object_files and sharedObject_files inside the lib folder
 
 #copy c files from E:\incupie\structure_practice\main_codes to the src folder
 #copying c files
	cp	-r $(MainCode_DIR)/*.c	$(current_DIR)/$(project_name)/src

 # delete the main.c from src since it is a complete code not needed to be compiled
	rm $(current_DIR)/$(project_name)/src/main.c

 # directory conatins the .c files is src
 #	cfile_DIR= $(current_DIR)/$(project_name)/src
	cp	-r $(MainCode_DIR)/*.c	$(current_DIR)
 # destinationa folder where object files will be stored
 #	objfile_DIR= $(current_DIR)/$(project_name)/lib/Object_files

 # Define a list of .c files only in the src
 #	SRC_FILES = $(wildcard $(cfile_DIR)/*.c)

 # create a list of the object files, replacing .c extension and creating a file
 # OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

 # Rule to compile .c files into .o files
  #	cd $(project_name)/src && gcc -c -fPIC delete_files_folders_function.c -o delete_files_folders_function.o

new1:	delete_files_folders_function.c delete_instructions_wwc.c

	gcc -c -fPIC delete_files_folders_function.c -o delete_files_folders_function.o

	gcc -c -fPIC delete_instructions_wwc.c -o delete_instructions_wwc.o

	gcc -o murged.o delete_files_folders_function.o delete_instructions_wwc.o -lm

new2:	
	gcc -shared -o deleteFileFolder.so delete_files_folders_function.o delete_instructions_wwc.o 

	cp	-r $(current_DIR)/*.so	$(current_DIR)/$(project_name)/src

copy_file:
	cp $(current_DIR)/*.o	$(current_DIR)/$(project_name)/lib/Object_files
	cp $(current_DIR)/*.so	$(current_DIR)/$(project_name)/lib/sharedObject_files

clean:
 	# rm -f $(current_DIR)/*.c
	rm -f $(current_DIR)/$(project_name)/src/*.o
	rm -f $(current_DIR)/*.c
	rm -f $(current_DIR)/$(project_name)/src/*.so
	rm -f $(current_DIR)/*.o
	rm -f $(current_DIR)/*.so

copy_again:
	cp $(current_DIR)/$(project_name)/lib/Object_files/murged.o	$(current_DIR)