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
  //printf("%s\n",strDup);
  int numLetters = word_terminator(ptr) - word_start(ptr);
  printf("number of letters: %d\n",numLetters);
  //char* strDup = copy_str(ptr,numLetters);
  char **tokens = tokenize(ptr);
  return 1;
 
}
