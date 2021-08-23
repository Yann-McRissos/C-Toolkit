#include "io/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *load_value(const char *filename, const char *key)
{
	FILE *descFile; // file descriptor
	char *value = malloc(20), *tokens, delim[] = "=\n", buffer[50];
	// delim[] contains the separators for lines or key/values

	descFile = fopen(filename, "r");
	if (descFile == NULL)
	{
		printf("Erreur à l'ouverture du fichier: %d\n", errno);
		return NULL;
	}
	/* reads file line by line until EOF is reached or value is found */
	while (fgets(buffer, 50, descFile) != NULL) // fgets returns NULL if EOF is reached
	{
		tokens = strtok(buffer, delim); // retrieve key
		if (!strcmp(tokens, key))
		{
			value = strtok(NULL, delim); // retrieve value
			fclose(descFile);
			//printf("val:%s\n", value);	// DEBUG
			return strdup(value);
		}
	}
	/* EOF reached, nothing found */
	fclose(descFile);
	return NULL;
}