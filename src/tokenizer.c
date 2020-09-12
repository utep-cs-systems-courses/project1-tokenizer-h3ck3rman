#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c<'!')
    {
      printf("%c is a space\n", c);
      return 1;
    }
  else
    {
      printf("%c is not a space\n", c);
      return 0;
    }
}

