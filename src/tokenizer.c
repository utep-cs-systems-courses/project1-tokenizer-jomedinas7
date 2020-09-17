#include <stdio.h>
#include <stdlib.h>

int space_char(char c)
{  
  if(c == ' ' || c == '\t' || c == '\0')
  {
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
 if(c == ' ' || c == '\t' || c == '\0')
  {
    return 0;
  }
  return 1;
  
}

char *word_start(char *str)
{
  int index = 0;
  //if there is a space at the beginning of the string, this will skip over them until a character is found
  while(space_char(str[index])
  {
    index++;
  }
    // str = &str[index];
    //returning the same pointer str, but modified to point to the first character of the word  
  return str+index;
}

char *word_terminator(char *str)
{
  int index = 0;
  while(non_space_char(str[index])
  {
    index++;
  }
    return str+index;
}

int count_words(char *str)
{
  return 0;
}
  


  
  
