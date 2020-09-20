#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
  List *hist = malloc(sizeof(List));
  hist -> root = 0;
  return hist;
}

void add_history(List *list, char *str)
{
  int nodeID = 1;
  Item *ptr = list->root;
  if(ptr == 0)
  {
    printf("This list is empty\n");
  }
  else{
    while(ptr ->next != 0)
    {
	ptr = ptr->next;
	nodeID++;
    }
  }
  Item *newNode = malloc(sizeof(Item));
  newNode -> id = nodeID;
  char* strEnd = str;
  while(*strEnd++)
  {
    ;
  }
  char* strCopy = (char *)malloc((strEnd-str)*sizeof(char));
  int i;
  for(i =0; i < strEnd-str;i++)
  {
    strCopy[i] = str[i];
  }
  strCopy[i] = '\0';
  newNode ->str = strCopy;
  
  newNode ->next = 0;
  if(ptr == 0){
    list->root = newNode;
  }
  else{
  ptr ->next = newNode;
  }
}

char *get_history(List *list, int id)
{
  Item *ptr = list -> root;
  int nodeIdx = 1;
  while(ptr -> next)
  {
    if(nodeIdx== id)
      {
	return ptr->str;
      }
    ptr = ptr -> next;
    nodeIdx++;
  }
  return '\0';
}

void print_history(List *list)
{
  Item *ptr = list -> root;
  printf("This is the root: %s\n",ptr->str);
  while(ptr!=0)
  {
    printf("%s\n",ptr -> str);
    ptr = ptr->next;
  }
}
void free_history(List *list)
{
  Item *ptr = list -> root;
  Item *temp;
  while(ptr != 0){
    temp = ptr->next;
    free(ptr);
    ptr = temp;
  }
  free(ptr);
  free(list);
}

int main()
{
  List *list1 = init_history();
  char *str1 = "hello";
  char *str2 = "bitch";
  char *str3 = "working";
  add_history(list1,str1);
  add_history(list1,str2);
  add_history(list1,str3);
  print_history(list1);
  free_history(list1);
  print_history(list1);
}
