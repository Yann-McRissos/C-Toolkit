#ifndef _FILES_H
#define _FILES_H

/*	Everything that has to do with files goes here */

/*	Loads the value associated to key in the config file filename
	
	On success: returns the desired value
	On failure: returns NULL */
char* load_value(const char *filename, const char *key);

#endif