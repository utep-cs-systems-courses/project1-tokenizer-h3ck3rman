#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c)
{
  return c < '!';
}

int non_space_char(char c)
{
  return c >= '!';
}

char *word_start(char *str)
{
  int i;
  for(i = 0; str[i] != '\0'; i++)
    {
      if(non_space_char(str[i]))
	{
	  return &str[i];
	}
    }
  return &str[i];
}

char *word_terminator(char *word)
{
  int i;
  for(i = 0; word[i] != '\0'; i++)
    {
      if(space_char(word[i]))
	{
	  return &word[i];
	}
    }
  return &word[i];
}

int count_words(char *str)
{
  int counter = 0;
  char *temp = word_start(str);
  while(temp[0] != '\0')
    {
      if(non_space_char(temp[0]))
	{
	  counter++;
	}
      temp = word_terminator(temp);
      temp = word_start(temp);
    }
  return counter;
}

char *copy_str(char *inStr, short len)
{
  char *copy = malloc((len+1) * sizeof(char));
  for(int i = 0; i < len; i++)
    {
      copy[i] = inStr[i];
    }
  copy[-1] = '\0';
  return copy;
}

char **tokenize(char *str)
{
  int num_words = count_words(str);
  char **token_words = malloc((num_words+1)*sizeof(char *));
  char *temp = str;
  int i;
  for(i = 0; i < num_words; i++)
    {
      char *start = word_start(temp);
      temp = word_terminator(start);
      int size = temp-start;
      token_words[i] = copy_str(start,size);
    }
  token_words[i] = 0;
  return token_words;
}

void print_tokens(char **token)
{
  for(int i = 0; token[i] != 0; i++)
    {
      printf("Token %d: %s\n", i, token[i]);
    }
}

void free_tokens(char** token)
{
  for(int i = 0; token[i] != 0; i++)
    {
      free(token[i]);
    }
  free(token);
}




