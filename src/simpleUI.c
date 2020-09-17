#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"

int main()
{
  printf("$");
  char str[50];
  scanf("%[^\n]s",str,50);
  printf(str);
  printf("\n");

  int index = 0;
  int numSpaces = 0;
  while(str[index] != '\0')
  {
    if(space_char(str[index]))
    {
      numSpaces++;
    }
    index++;
  }
  printf("There are ");
  printf("%d", numSpaces);
  printf(" in this String.");
  printf("\n");

  return 1;
 
}
