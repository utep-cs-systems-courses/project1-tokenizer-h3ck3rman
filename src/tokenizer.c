#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c < '!')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

int non_space_char(char c)
{
  if(c >= '!')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}

char *word_start(char *str)
{
  int n = 0;
  while(space_char(str[0+n]) == 1)
    {
      n++;
    }
  return &str[0+n];
}








