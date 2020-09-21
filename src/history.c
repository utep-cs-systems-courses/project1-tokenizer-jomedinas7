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
    //It is what it is...
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
  while(ptr != 0)
  {
    if(nodeIdx== id)
      {
	return ptr->str;
      }
    ptr = ptr -> next;
    nodeIdx++;
  }
  return "That history ID was not found";
}

void print_history(List *list)
{
  Item *ptr = list -> root;
  // printf("This is the root: %s\n",ptr->str);
  while(ptr!=0)
  {
    printf("ID: %d, %s\n",ptr -> id,ptr -> str);
    ptr = ptr->next;
  }
}
void free_history(List *list)
{
  Item *ptr = list -> root;
  Item *temp;
  while(ptr != 0){
    temp = ptr->next;
    free(ptr -> str);
    ptr -> str = NULL;
    free(ptr);
    ptr = temp;
  }
  free(list->root);
  list -> root = NULL;
  free(list);
  list = NULL;
}

