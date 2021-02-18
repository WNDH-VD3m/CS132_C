#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp1;
	FILE *fp2;
	int ch;
	
	if((fp1 = fopen("hello.txt", "r"))==NULL)
	{
		printf("Fail to open!\n");
		exit(EXIT_FAILURE);
	}
	
	if((fp2 = fopen("copyhello.txt", "w"))==NULL)
        {
                printf("Fail to open!\n");
                exit(EXIT_FAILURE);
        }
	
	while((ch = fgetc(fp1)) != EOF)
	{
		fputc(ch,fp2);
	}

	fclose(fp1);
	fclose(fp2);
	
	return 0;
	
}
