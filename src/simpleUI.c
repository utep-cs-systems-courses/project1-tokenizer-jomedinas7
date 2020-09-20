#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"

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
  char* ptr = str;
  printf("Words in this string: %d\n",count_words(ptr));
  char **tokens = tokenize(ptr);
  // print_tokens(tokens);
  List *list1 = init_history();
  int i = 0;
  while(tokens[i]){
    add_history(list1,tokens[i]);
    i++;
  }
  print_history(list1);
  // free_tokens(tokens);
  return 1;
 
}
