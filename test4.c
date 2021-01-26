#include <stdio.h>

int main()
{
	FILE *fp = NULL;

	fp = fopen("test4.txt", "a+");
	fprintf(fp, "This is a testing for printf.\n");
	fputs("This is testing for fputs.\n",fp);
	fclose(fp);
}
