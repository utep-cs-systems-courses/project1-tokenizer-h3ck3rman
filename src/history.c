#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List   *list = malloc(sizeof(List));
  list -> root = malloc(sizeof(Item));

  return list;
}

void add_history(List *list, char *str)
{
  Item *temp = list -> root;
  int count = 0;
  while(temp -> next != NULL)
    {
      count++;
      temp = temp -> next;
    }
  temp -> id = count+1;
  temp -> str = str;
  temp -> next = malloc(sizeof(Item));
}
