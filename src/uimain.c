#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main(){

  List *hist = init_history();
  char s[50];
  puts("Welcome");

  printf("\ntokenize_function\n");
  printf("Enter string: ");
  scanf(" %[^\n]", s);
  char **tokens = tokenize(s);
  print_tokens(tokens);
  add_history(hist,s);
  free_tokens(tokens);

  Item *temp = hist -> root;
  printf("history = %d/%s\n",temp->id, temp->str);
  
  return 0;
}
  
