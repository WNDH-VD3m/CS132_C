#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp;
	int ch;

	if((fp = fopen("hello.txt", "r"))==NULL)
	{
		printf("打开失败\n");
		exit(EXIT_FAILURE);
	}
	while((ch = getc(fp))!=EOF)
	{
		putchar(ch);
	}
	fclose(fp);
	return 0;
}
