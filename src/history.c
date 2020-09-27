#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history()
{
  /* allocate memory for the List and set the root to 0 to indicate there are no Items in the list yet*/
  List *hist = malloc(sizeof(List));
  hist -> root = 0;
  return hist;
}

void add_history(List *list, char *str)
{
  /* given the string we point a pointer at the start of the word, and increment a counter as long as there are characters in the string */
  int strLen = 0;
  char *strPtr = str;
  while(*strPtr++){
      strLen++;
  }
  /* now knowing the size of the string, we know how many character sized slots we need to allocate memory for a copy of the string +1 for the \0 character*/
  char *strCopy = (char*)malloc((strLen+1)*sizeof(char));
  for(int i = 0; i<strLen;i++){
    strCopy[i] = str[i];
  }
  strCopy[strLen+1] = '\0';

  /*since the first Item node will be added to the history, we can say that the nodeId will be 1*/
  int nodeID = 1;
  /* allocate a slot of memory of size Item for the new node Item*/
  Item *newNode = malloc(sizeof(Item));
  /*assign the new Node Item's str and next attributes with the copy of the string, and 0 respectively to indicate the end of the list*/
  newNode ->str = strCopy;
  newNode ->next = 0;

  /*point a pointer to the root of the list, if the pointer points to a value 0, then we can place our newNode Item as the root */
  Item *ptr = list->root;
  if(list->root == 0)
  {
    newNode -> id = nodeID;
    list -> root = newNode;
  }
  /*increment the nodeID as long as there are list Items to point to, if the next item in the list is 0, we will know to place our new Node Item there*/
  else{
    nodeID++;
    while(ptr->next != 0)
    {
	ptr = ptr->next;
	nodeID++;
    }
    newNode -> id =nodeID;
    ptr ->next = newNode;
  }
  
}

char *get_history(List *list, int id)
{
  /*given that the root ID will be 1, we can increment a counter alongside traversal of the list until the Item ID matches the id passed in the parameters*/
  Item *ptr = list -> root;
  int nodeIdx = 1;
  while(ptr != 0)
  {
    if(ptr->id == id)
      {
	return ptr->str;
      }
    ptr = ptr -> next;
    nodeIdx++;
  }
  /*if the id we were given is not found because it is either too big or non-existent, we return this statement to be printed*/
  return "That history ID was not found";
}

void print_history(List *list)
{
  /*print the ID of the list Item alongside with the string that the Item holds, traversing the list until we reach 0*/
  Item *ptr = list -> root;
  while(ptr!=0)
  {
    printf("ID: %d, %s\n",ptr -> id,ptr -> str);
    ptr = ptr->next;
  }
}
void free_history(List *list)
{
  /*we have to free every slot of allocated memory for each Item in the List, and then free the list itself*/
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

