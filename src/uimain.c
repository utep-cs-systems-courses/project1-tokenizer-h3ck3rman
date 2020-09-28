#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{

  List *hist = init_history(); // Initilize linked list variable
  puts("Welcome!\n");
  
  while(1) // Infinite loop
    {
      char input[200];
      char string[200];

      printf("\n\nPress 't' to tokenize");
      printf("\nPress 'h' to view all input history");
      printf("\nPress '!' followed by ID to view specific history input");
      printf("\nPress 'q' to quit\n");
      printf("\n> ");
      scanf(" %[^\n]", input);

      if(input[0] == 't') // Typed input is tokenized, printed, and stored to history linked list
	{
	  printf("\ntokenize_function\n");
	  printf("Enter string: ");
	  scanf(" %[^\n]", string);
	  char **tokens = tokenize(string);
	  print_tokens(tokens);
	  add_history(hist,string);
	  free_tokens(tokens);
	}
      
      else if(input[0] == 'h') // View previous tokenized words
	{
	  print_history(hist);
	}

      else if(input[0] == '!') // View a specific history id
	{
	  int id = atoi(input + 1);
	  printf("\n%s\n", get_history(hist, id));
	}
 
      else if(input[0] == 'q') // Free the history from memory and quit infinite loop
	{
	  printf("\nThank you for using Tokenizer!\n");
	  free_history(hist);
	  return 0;
	}
      
      else //Input not accepted
	{
	  printf("Input is invalid\n");
	}
    }
}
  
