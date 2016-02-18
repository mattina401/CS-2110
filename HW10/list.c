#include <stdlib.h>
#include "./list.h"
#include "my_malloc.h"
/*
Jongyeon Kim
*/


LIST* create_list()
{
	LIST *lst = (LIST*)malloc(sizeof(LIST));
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
	return lst;
}

NODE* create_node(int data)
{
	NODE *nd = (NODE*)malloc(sizeof(NODE));
	nd->data = data;
	nd->next = NULL;
	nd->prev = NULL;
	return nd;
}
int currentVal1 = 0;
int currentVal2 = 0;

/**
 * pushFront
 * Takes in ptr to a list and data to add
 * Should add new node containing the data to the head of the list, and increment size
 */
void pushFront(LIST *list, int data)
{
	NODE *newNode = create_node(data);
	/*
	when list's size is 0
	*/
	if (list -> size == 0)
	{
		list -> head = newNode;
		list -> tail = newNode;
	}
	/*
	when list has some nodes
	*/
	else
	{
		/*
		head movex to <-
		*/
		newNode -> next = list -> head;
		list -> head -> prev = newNode;
		list -> head = newNode;
	}
	list -> size++;


}

/**
 * pushFront
 * Takes in ptr to a list and data to add
 * Should add new node containing the data to the tail of the list, and increment size
 */
void pushBack(LIST *list, int data)
{
	NODE *newNode = create_node(data);

	/*
	when list's size is 0
	*/
	if (list -> size == 0)
	{
		list -> head = newNode;
		list -> tail = newNode;
	}
	/*
	when list has some nodes
	*/
	else
	{
		/*
		tail movex to ->
		*/
		newNode -> prev = list -> tail;
		list -> tail -> next = newNode;
		list -> tail = newNode;
	}
	list -> size++;
}

/**
 * popFront
 * Takes in ptr to a list
 * Remove and free node at the front of the list, and decrement size
 * Return the value of that node
 * Return 0 if the size of the list is 0
 */
int popFront(LIST *list)
{
	NODE *current = list -> head;
	/*
	when list's size is 0
	*/
	if (list -> size == 0)
	{
		return 0;
	}

	currentVal1 = current->data;
	/*
	when list have only one node
	*/
	if(list -> size == 1)
	{
		/*
		basement state
		*/
		list->head = NULL;
		list->tail = NULL;
		list->size--;
		return currentVal1;
	}
	/*
	head movex to ->
	*/
	list -> head = list-> head-> next;
	list -> head -> prev = NULL;
	list -> size--;
	free(current);
	return currentVal1;
	
}

/**
 * popBack
 * Takes in ptr to a list
 * Remove and free node at the back of the list, and decrement size
 * Return the value of that node
 * Return 0 if the size of the list is 0
 */
int popBack(LIST *list)
{
	NODE *current = list -> tail;
	/*
	when list's size is 0
	*/
	if (list -> size == 0)
	{
		return 0;
	}

	currentVal2 = current->data;

	/*
	when list have only one node
	*/
	if(list -> size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size--;
		return currentVal2;
	}

	/*
	tail movex to <-
	*/
	list -> tail = list -> tail -> prev;
	list -> tail -> next = NULL;
	list -> size--;
	free(current);

	return currentVal2;
}

/*
void print_node(LIST* llist)
{
	NODE* current = llist->head;
	if(llist->size == 0)
	{
		printf("\n");
		return;
	}

	printf("%d", llist->head->data);
	while(current->next != NULL)
	{
		current = current->next;
		printf(" %d", current->data);
	}
	printf("\n");
}
*/
