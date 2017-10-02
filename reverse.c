/**
	Created by Dylan Kernohan on 9/19/2017
**/

#include <stdio.h>
#include <stdlib.h>
#include "file_utils.h"



/******************************************************************************************
	Driver Program that reads a text file, reverses the text, and writes it to another file. 
********************************************************************************************/

int main( int argc, char** argv){

	// Check if both parameters were passed into main
	if (argc < 3){
		fprintf( stderr, "Error: Not enough parameters.\n" );
		return -1;
	}

	// Creates a pointer to a pointer and allocates memory
	char* buffer; 
	
	// Read the file passed by the first argument
	int size = read_file(argv[1], &buffer);

	// Create a second pointer for the reversed string and allocate memory
	char* reversedBuffer;
	reversedBuffer = (char*) malloc(size * sizeof(char));

	// Reverse the string
	int i;
	for ( i = size; i > 0; i = i - 1){
		reversedBuffer[size - i] = buffer[i - 1];
	}

	// Write the new string to the file passed by the second argument
	write_file( argv[2], reversedBuffer, size );

	if (size == -1){
		free(buffer); 	// Unallocate the buffer
		return -1;
	}
	
	free(buffer);		// Unallocate the buffer
	return size;
	

}