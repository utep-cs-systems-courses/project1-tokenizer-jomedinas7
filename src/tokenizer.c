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
  while(space_char(str[index]))
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
  while(non_space_char(str[index]))
  {
    index++;
  }
    return str+index;
}

int count_words(char *str)
{
  int num_words = 0;
  char *ptr = str;
  while(space_char(*ptr))
  {
    ptr++;
  }
  if(*ptr == '\0')
  {
    return num_words; 
  }
  while(*ptr != '\0')
  {
    ptr = word_start(ptr);
    ptr = word_terminator(ptr);
    num_words++;
  }
  return num_words;
}

char* copy_str(char *inStr, short len)
{
  char *p;
  p = (char *)malloc((len+1)*sizeof(char));
  if(!p){
    printf("Memory allocation failed");
  }
  for(int i = 0; i<len; i++)
  {
    p[i] = inStr[i];
  }
  p[len+1]= '\0';
  // printf("Copied String:%s\n",p);
  return p;

}

char **tokenize(char *inStr)
{
  int numWords = count_words(inStr);
  char **tokens = (char**)malloc(sizeof(char*)*(numWords+1));
  char* wordProg = inStr;
  int i = 0;
  for(i = 0; i <numWords; i++)
  {
    tokens[i] = copy_str(wordProg,(word_terminator(wordProg)-word_start(wordProg)));
    wordProg = word_start(wordProg);
    wordProg = word_terminator(wordProg);
    wordProg = word_start(wordProg);
  }
  tokens[i] = '\0';
  return tokens;
  
}

void print_tokens(char **tokens)
{
  int index = 0;
  while(tokens[index])
    {
      printf("%s\n",tokens[index],index);
      index++;
    }
}
  


  
  
