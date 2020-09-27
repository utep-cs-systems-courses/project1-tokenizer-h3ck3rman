#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  return c < '!';
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  return c >= '!';
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str. Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  int i;
  for(i = 0; str[i] != '\0'; i++)  
    {
      if(non_space_char(str[i])) // Traverses string and returns the first character
	{
	  return &str[i];
	}
    }
  return &str[i];
}

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  int i;
  for(i = 0; word[i] != '\0'; i++)
    {
      if(space_char(word[i])) // Traverses word and returns the first space character found
	{
	  return &word[i];
	}
    }
  return &word[i];
}

/* Counts the number of words in the string argument. */
int count_words(char *str)
{
  int counter = 0; // Counter added to track the number of words
  char *temp  = word_start(str); // Temp string that starts at the first non-space char of string
  while(temp[0] != '\0')
    { 	
      counter++;
      temp = word_terminator(temp); // Point to next space char 
      temp = word_start(temp); // Point to next word
    }
  return counter;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copy = malloc((len+1) * sizeof(char)); // Allocates memory needed for string
  int i;
  for(i = 0; i < len; i++)
    {
      copy[i] = inStr[i]; // Characters in inStr are copied into allocated variable
    }
  copy[i] = '\0'; // Last value equals '\0' to to terminate string
  return copy;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str. */
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
      int length = temp-start; 
      token_words[i] = copy_str(start,length); // One word of the string is copied into a token
    }
  token_words[i] = 0; // Last element is set to null
  return token_words;
}

/* Prints all tokens. */
void print_tokens(char **token)
{
  for(int i = 0; token[i] != 0; i++)
    {
      printf("Token %d: %s\n", i, token[i]); // Prints one token/word at a time
    }
}

/* Frees all tokens and the vector containing them. */
void free_tokens(char** token)
{
  for(int i = 0; token[i] != 0; i++)
    {
      free(token[i]); // Every token is freed from memory
    }
  free(token); // The token pointer is freed
}




