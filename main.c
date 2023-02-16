#include <stdio.h>

int main(int argc, char* argv[])
{ 
  FILE *f;
  char buffer[256];
  f = fopen(argv[1], "r");
  while((fgets(buffer, 256, f))!=NULL)
        {
            printf("%s", buffer);
        }
        printf("\n");
        fclose(f);
  
    return 0;
}