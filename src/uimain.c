#include <stdio.h>
#include "tokenizer.h"

int main(){
  char c;
  char s[50];
  puts("Welcome");
 
  printf("\nspace_char function\n");
  printf("Enter Char: ");
  scanf("%c", &c);
  printf("%d",space_char(c));

  printf("\nnon_space_char function\n");
  printf("Enter Char: ");
  scanf(" %c", &c);
  printf("%d",non_space_char(c));

  printf("\nword_start function\n");
  printf("Enter string: ");
  scanf(" %[^\n]",s);
  printf("first non-space char is: %c\n", *word_start(&s[0]));
  return 0;
}
  
