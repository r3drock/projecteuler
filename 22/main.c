#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "names.txt"

int cnif();
int cnss(char **names, int size);

int strcomp(const void * a, const void * b)
{
	const char **ap = (const char **) a;
	const char **bp = (const char **) b;

	return strcmp(*ap, *bp);
}

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

	qsort(names, namecount, sizeof(char *),
		  strcomp);
	for (int i = 0; i < namecount; ++i)
		printf("%s\n",names[i]);
	
	printf("namescoresum: %d\n", cnss(names, namecount));
	return 0;
}

int cnss(char **names, int size) //calculatenamescoresum
{
	int sum = 0;

	for (int i = 0; i < size; ++i) {
		int subsum = 0;
		for (int j = 0; names[i][j] != '\0'; ++j) 
			subsum += (names[i][j] + 1) - 'A';
		sum += subsum * (i+1);
	}

	return sum;
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

