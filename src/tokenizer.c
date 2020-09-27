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
  /*if there is a space at the beginning of the string, this will skip over them until a character is found*/
  while(space_char(str[index])){
    index++;
  }
  /*returning the same pointer str, but modified to point to the first character of the word*/  
  return str+index;
}

char *word_terminator(char *str)
{
  int index = 0;
  /*we use this loop to know the length of the word until we hit a space character*/
  while(non_space_char(str[index])){
    index++;
  }
  /*returning the str pointer plus the indices to point it to the space character after the word*/
    return str+index;
}

int count_words(char *str)
{
  int num_words = 0;
  char *ptr = str;
  
  /*Initially need to skip any premptive spaces that the user may have inputted*/
  while(space_char(*ptr)){
    /*if we're still pointing to spaces, but the next character indicates the end of the string then we should return 0 since no word was found*/
    if(ptr[1] == '\0'){
      return 0;
    }
    ptr++;
  }
  /*if we are not pointing to space characters, but end up with an empty string, then return 0*/
  if(ptr[0] == '\0'){
    return num_words; 
  }
  while(*ptr != '\0') {
    /*point to the beginning of the next word*/
    ptr = word_start(ptr);
    /*point to the end of the word*/
    ptr = word_terminator(ptr);
    /*having been through a word from start to finish we can say that we can increment the number of words*/
    num_words++;
    if(ptr[0] == '\0'){
      return num_words;
    }
  }
  return num_words;
}

char* copy_str(char *inStr, short len)
{
  char *p;
  /*allocate memory for a copy of the string we recieve using as many char sized slots as there are in the word +1 for the \0 character*/
  p = (char *)malloc((len+1)*sizeof(char));
  if(!p){
    printf("Memory allocation failed");
  }
  /*using a loop to assign individual character values of the string to our newly allocated memory*/
  for(int i = 0; i<len; i++)
  {
    p[i] = inStr[i];
  }
  /*signaling the ending of our string copy with the \0 character*/
  p[len+1]= '\0';
  return p;

}

char **tokenize(char *inStr)
{
  int numWords = count_words(inStr);
  char **tokens = (char**)malloc(sizeof(char*)*(numWords+1));
  char* wordProg = inStr;
  int i = 0;
  while(space_char(*wordProg)){
     wordProg++;
    }
  /*this loop will copy words one at a time using the copy_str method, we use the difference in indices between the pointers from word_terminator and word_start as the length of the word*/
  for(i = 0; i <numWords; i++){
    tokens[i] = copy_str(wordProg,(word_terminator(wordProg)-word_start(wordProg)));
    /*Here we move the pointer through the words similar to how we did in count_words, but now we make sure to start the loop with the pointer at the beginning of the next word */
    wordProg = word_start(wordProg);
    wordProg = word_terminator(wordProg);
    wordProg = word_start(wordProg);
  }
  /*Making sure to indicate the end of the token array with the \0 character*/
  tokens[i] = '\0';
  return tokens;
  
}

void print_tokens(char **tokens)
{
  int index = 0;
  while(tokens[index])
    {
      printf("%s\n",tokens[index]);
      index++;
    }
}
void free_tokens(char **tokens)
{
  /*Every malloc needs to have a free, so we free the memory used for every word inside of the tokens array, then we free the memory allocated for the tokens array itself*/
  for(int i = 0; tokens[i];i++)
  {
    free(tokens[i]);
    tokens[i] = NULL;
  }
  free(tokens);
  tokens = NULL;
}


  
  
