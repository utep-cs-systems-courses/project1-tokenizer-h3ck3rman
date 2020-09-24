#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{

  List *hist = init_history();
  puts("Welcome!\n");
  
  while(1)
    {
      char input[200];
      char string[200];

      printf("\n\nPress 't' to tokenize");
      printf("\nPress'h' to view all input history");
      printf("\nPress '!' followed by ID to view specific history input");
      printf("\nPress 'q' to quit\n");
      printf("\n> ");
      scanf(" %[^\n]", input);

      if(input[0] == 't')
	{
	  printf("\ntokenize_function\n");
	  printf("Enter string: ");
	  scanf(" %[^\n]", string);
	  char **tokens = tokenize(string);
	  print_tokens(tokens);
	  add_history(hist,string);
	  free_tokens(tokens);
	}
      
      else if(input[0] == 'h')
	{
	  print_history(hist);
	}

      else if(input[0] == '!')
	{
	  int id = atoi(input + 1);
	  printf("\n%s\n", get_history(hist, id));
	}
 
      else if(input[0] == 'q')
	{
	  printf("\nThank you for using Tokenizer!\n");
	  free_history(hist);
	  return 0;
	}
      
      else
	{
	  printf("Input is invalid\n");
	}
    }
}
  
