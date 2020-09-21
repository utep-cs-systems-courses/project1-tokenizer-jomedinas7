#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"

int main()
{
  printf("Hello, please enter a string: \n\n");
  printf("$");
  char str[50];
  scanf("%[^\n]s",str,50);
  printf("Your string is: %s\n",str);
  
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
  int id;
  while(1)
  {
    printf("Which string would you like to pull from the history? (or enter any non-integer to exit)\n $");
    int key = scanf("%d",&id);
    printf("%d",key);
    if(key == 0)
      {
	break;
      }
    else
      {
	printf("%s\n",get_history(list1,id));
      }
   }
  // print_history(list1);
  free_tokens(tokens);
  free_history(list1);
  return 1;
 
}
