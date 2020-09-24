#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List* init_history()
{
  List   *list = malloc(sizeof(List));
  list -> root = malloc(sizeof(Item));

  return list;
}

void add_history(List *list, char *str)
{
  Item *temp = list -> root;
  int count = 1;
  while(temp -> next != NULL)
    {
      count++;
      temp = temp -> next;
    }
  temp -> next = malloc(sizeof(Item));
  temp -> id = count;
  temp -> str = copy_str(str, 50);
}

char *get_history(List *list, int id)
{
  Item *temp = list -> root;
  while(temp != 0)
    {
      if(temp -> id == id)
	{
	  char *string = temp -> str;
	  return string;
	}
      temp = temp -> next;
    }
  return "ID could not be located";
}

void print_history(List *list)
{
  Item *temp = list -> root;
  while(temp -> next != NULL)
    {
      printf("%d. %s\n", temp -> id, temp -> str);	
      temp = temp -> next;
    }
}

void free_history(List *list)
{
  Item *temp = list -> root;
  while(temp -> next != NULL)
    {
      free(temp -> str);
      Item *temp2 = temp -> next;
      free(temp);
      temp = temp2;
    }
  free(temp -> str);
  free(temp);
  free(list);
}
