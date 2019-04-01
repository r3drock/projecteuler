#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "names.txt"

int cnif();
void qsort(char **names);
int calculatenamescores();

int main()
{
	char **names;
	int namecount = cnif();
	if (namecount == -1) {
		printf("File names.txt not found!");
		return -1;
	}

	names = malloc(sizeof(char *) * namecount);
	FILE *fp;
	fp = fopen(FILENAME,"r");
	if (fp == NULL) {
		printf("File names.txt not found!");
		return -1;
	}

	int  c;
	char name[30];

	int j = 0; 
	int insidequotationmarks = 1;
	while ((c = getc(fp)) != EOF) {
		if (c != '\"' && insidequotationmarks) {
			int i = 0;
			do {
				name[i++] = (char) c;
			} while ((c = getc(fp)) != EOF && 'A' <= c && c <= 'Z'); 
			name[i] = '\0';
			names[j] = malloc(strlen(name) + 1);
			strcpy(names[j++], name);
			insidequotationmarks = 0;
		} else
			insidequotationmarks = 1;
	}

	qsort(names);
	for (int i = 0; i < namecount; ++i)
		printf("%s\n",names[i]);
	calculatenamescoresum(names, namecount);
	return 0;
}

int calculatenamescoresum(char **names, int size)
{
	int sum = 0;
	char c = 0;

	for (int i = 0; i < size; ++i) 
		for (int j = 0; names[i][j] != '\0'; ++j) 
			sum += (names[i][j] + 1) - 'A';

	return 0;
}

int cnif() // count names in file
{
	FILE *fp;
	fp = fopen(FILENAME,"r");
	if (fp == NULL)
		return -1;

	int len = 0;
	int c;
	while ((c = getc(fp)) != EOF)
		if (c == '\"')
			++len;

	fclose(fp);
	return len / 2;
}

void qsort(char **names)
{
}
