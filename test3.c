#include <stdio.h>
#include <stdlib.h>

#define MAX 1024


int main()
{
  FILE *fp;
  char buffer[MAX];

  if((fp = fopen("lines.txt", "w")) == NULL)
  {
    printf("Fail to open!\n");
    exit(EXIT_FAILURE);
  }

  fputs("Hello world!\n" , fp);
  fputs("test!!!\n", fp);
  fputs("HAHAHAHA\0", fp);

  fclose(fp);

  if((fp = fopen("lines.txt", "r")) == NULL)
  {
    printf("Fail to open!\n");
    exit(EXIT_FAILURE);
  }
  while (!feof(fp))
  {
    fgets(buffer, MAX , fp);
    printf("%s", buffer);
  }

  return 0;

}
