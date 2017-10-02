/**
	Created by Dylan Kernohan on 9/19/2017
**/

#ifndef __H_FILE_UTILS__
#define __H_FILE_UTILS__

/**
	Reads a file
**/
int read_file( char* filename, char **buffer );


/**
	Writes to a file
**/
int write_file( char* filename, char *buffer, int size );


#endif