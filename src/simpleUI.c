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
  printf("Spaces in string:  %d\n", numSpaces);

  char* ptr = str;
  printf("Words in this string: %d\n",count_words(ptr));
  char **tokens = tokenize(ptr);
  printf("Tokens address: %p\n", &tokens);
  printf("Tokens address[0]: %p\n", &tokens[0]);
  print_tokens(tokens);
  free_tokens(tokens);
  return 1;
 
}
