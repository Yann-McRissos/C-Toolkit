#include "io/files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *loadProp(const char *filename, const char *property)
{
	FILE *descFile; // file descriptor
	//char filename[] = "serveur_production.txt";
	char *value = malloc(20), *tokens, delim[] = "=\n", buffer[50];

	// Ouverture fichier
	descFile = fopen(filename, "r");
	if (descFile == NULL)
	{
		printf("Erreur à l'ouverture du fichier: %d\n", errno);
		return NULL;
	}
	/* reads file line by line until EOF is reached or prop is found */
	while (fgets(buffer, 50, descFile) != NULL) // fgets returns NULL if EOF is reached
	{
		tokens = strtok(buffer, delim); // retrieve Property
		if (!strcmp(tokens, property))
		{
			value = strtok(NULL, delim); // retrieve Value
			fclose(descFile);
			//printf("val:%s\n", value);
			return strdup(value);
		}
	}
	/* EOF reached, nothing found */
	fclose(descFile);
	return NULL;
}