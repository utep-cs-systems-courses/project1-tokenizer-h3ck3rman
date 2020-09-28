#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List   *list = malloc(sizeof(List)); // Allocate list memory
  list -> root = malloc(sizeof(Item)); // Allocate item memory

  return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store */
void add_history(List *list, char *str)
{
  Item *temp = list -> root;
  int count = 1;
  while(temp -> next != NULL) // String is added as an item to the end of linked list
    {
      count++;
      temp = temp -> next;
    }
  temp -> next = malloc(sizeof(Item)); // Memory for next item is allocated
  temp -> id = count;
  temp -> str = copy_str(str, 200);
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *temp = list -> root; 
  while(temp != 0) // Temp item traverses list until id is found
    {
      if(temp -> id == id)
	{
	  char *string = temp -> str;
	  return string;
	}
      temp = temp -> next;
    }
  return "ID could not be located"; // The id value is not valid
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *temp = list -> root;
  while(temp -> next != NULL) // All items in the list are printed
    {
      printf("%d. %s\n", temp -> id, temp -> str);	
      temp = temp -> next;
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *temp = list -> root;
  while(temp -> next != NULL) // Items and strings within are freed from memory
    {
      free(temp -> str);
      Item *temp2 = temp -> next; // Second temp needed to point to next node once current is free
      free(temp);
      temp = temp2;
    }
  // Free last node and its contents from memory + free list from memory
  free(temp -> str);
  free(temp);
  free(list);
}
