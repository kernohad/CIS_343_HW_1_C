/****************************************************************
	Created by Dylan Kernohan on 9/19/2017

	I referenced this for help: http://devdocs.io/c
****************************************************************/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "file_utils.h"

/***************************************************************
	Reads a file
****************************************************************/
int read_file( char* filename, char **buffer ){

	// Find the size of the 
	struct stat st;
	stat(filename, &st);
	int size = st.st_size;


	// allocates memory to the pointer buffer
	*buffer = (char*) malloc(size * sizeof(char));	

	// Opens the file
	FILE *fp;
	fp = fopen( filename, "r");
	
	// Check if the file exists to read from
	if(!fp) {
        perror("File opening failed");
        return -1;
    }

    // Reads the file and stores the size of what was read into readSize
	size_t readSize = fread(*buffer, sizeof **buffer, size, fp);

	// Closes the file
	fclose(fp);

	// Checks if the whole file was read, or if it stopped part way through. 
	if ( readSize == size){
		return size;
	}
	else {
	   fprintf( stderr, "Error reading file.\n" ); 
       return -1;
	 }
}


/******************************************************************
	Writes to a file
*******************************************************************/
int write_file( char* filename, char *buffer, int size ){

	// Opens the file
	FILE *fp;
	fp = fopen( filename, "w+");

	// Writes the file and stores the size of what was written into writeSize
	size_t writeSize = fwrite(buffer, sizeof *buffer, size, fp);

	// Closes the file
	fclose(fp);

	// Checks if the whole file was written, or if it stopped part way through. 
	if ( writeSize == size){
		return size;
	}
	else {
	   fprintf( stderr, "Error writing file.\n" ); 
       return -1;
	 }
}