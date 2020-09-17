#include <stdio.h>
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
  for(int i = 0; str[i] != '\0'; i++)
    {
      if(non_space_char(str[i]))
	{
	  return &str[i];
	}
    }
  return &str[0];
}

char *word_terminator(char *word)
{
  for(int i = 0; word[i] != '\0'; i++)
    {
      if(non_space_char(word[i]) && space_char(word[i+1]))
	{
	  return &word[i+1];
	}
    }
  return word;
}

int count_words(char *str)
{
  int counter = 0;
  char *word = word_start(&str[0]);
  while(*word != '\0')
    {
      if(non_space_char(*word))
	{
	  counter++;
	}
      word = word_terminator(word);
      word = word_start(word);
    }
  return counter;
}








