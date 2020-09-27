#include <stdio.h>
#include <stdlib.h>

#include "tokenizer.h"
#include "history.h"

int main()
{
  List *list1 = init_history();
  char input[80];
  while(1)
  {
    printf("Hello, enter @ to stop inputing strings, or & to input a new string: \n\n");
    printf("$");
    char str[50];
    fgets(str,50,stdin);
    // printf("Your string is: %s\n",str);
    if(str[0] == '@'){
      printf("You're done inputing strings\n");
      break;
    }
    if(str[0] == '&'){
      printf("$");
      printf("%c",272);
      fgets(input,80,stdin);
 
      char* ptr = input;
      printf("Words in this string: %d\n",count_words(ptr));
      char **tokens = tokenize(ptr);
      print_tokens(tokens);
      free_tokens(tokens);
      add_history(list1,ptr);
    }
  }
  print_history(list1);
  
  int id;
  while(1)
  {
    printf("Which string would you like to pull from the history? (or enter any non-integer to exit)\n $");
    int key = scanf("%d",&id);
    if(key == 0)
      {
	break;
      }
    else
      {
	printf("%s\n",get_history(list1,id));
      }
   }
  free_history(list1);
  return 1;
 
}
