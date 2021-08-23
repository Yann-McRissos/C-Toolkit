#ifndef _FILES_H
#define _FILES_H

/*	Everything that has to do with files goes here */

/*	Loads the value associated to property in the config file filename
	
	On success: returns the desired value
	On failure: returns NULL */
char* loadProp(const char *filename, const char *property);

#endif