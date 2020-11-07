/*
 * LinkedList.c
 *
 *  Created on: 6 nov. 2020
 *      Author: damien
 */


#include "LinkedList.h"
#include <malloc.h>
#include <string.h>

struct ListCell
{
	void *value;
	struct ListCell *next;
};

struct ListCell *ListCell_new(void *value)
{
	struct ListCell *self = calloc(sizeof(struct ListCell), 1);
	self->value = value;
	return self;
}

void ListCell_free(struct ListCell *self)
{
	if(self->next != NULL)
		ListCell_free(self->next);
	free(self);
}

void ListCell_set_next(struct ListCell *self, struct ListCell *nextcell)
{
	if(self->next != NULL)
	{
		if(nextcell != NULL)
			ListCell_set_next(nextcell, self->next);
	}
	self->next = nextcell;
}

void LinkedList_init(struct LinkedList *self)
{
	memset(self, 0, sizeof(struct LinkedList));
}

void LinkedList_empty(struct LinkedList *self)
{
	if(self->cells != NULL)
		ListCell_free(self->cells);
	self->cells = NULL;
	self->last = NULL;
	self->count = 0;
}

void LinkedList_finalize(struct LinkedList *self)
{
	LinkedList_empty(self);
}

size_t LinkedList_get_count(struct LinkedList *self)
{
	return self->count;
}

void LinkedList_do_to_all(struct LinkedList *self, void (*func)(void*, void*), void *arg)
{
	if(func == NULL)
		return;
	struct ListCell *cell = self->cells;
	while(cell != NULL)
	{
		func(cell->value, arg);
		cell = cell->next;
	}
}

void *LinkedList_remove_with_compare_func(struct LinkedList *self, int (*func)(void*, void*), void *value)
{
	void *return_value;
	int ret_compare = -1;
	if(func == NULL || value == NULL)
		return;
	struct ListCell *cell = self->cells, *prev = NULL;
	while(cell != NULL)
	{
		if((ret_compare = func(cell->value, value)) != 0)
		{
			prev = cell;
			cell = cell->next;
		}
		else
			break;
	}
	if(cell != NULL && ret_compare == 0)
	{
		return_value = cell->value;
		if(prev == NULL)//Cell found is first cell;
			self->cells = cell->next;
		else
			prev->next = cell->next;
		if(self->last == self->cells)
			self->last = cell->next;
		ListCell_free(cell);
		self->count--;
	}
	return return_value;
}

void LinkedList_remove(struct LinkedList *self, void *value)
{
	struct ListCell *cell = self->cells, *prev = NULL;
	while(cell != NULL)
	{
		if(cell->value != value)
		{
			prev = cell;
			cell = cell->next;
		}
		else
			break;
	}
	if(cell != NULL && cell->value == value)
	{
		if(prev == NULL)//Cell found is first cell;
			self->cells = cell->next;
		else
			prev->next = cell->next;
		if(self->last == self->cells)
			self->last = cell->next;
		ListCell_free(cell);
		self->count--;
	}
}

void LinkedList_append(struct LinkedList *self, void *value)
{
	struct ListCell *cell = ListCell_new(value);
	if(self->cells != NULL)
		ListCell_set_next(self->last, cell);
	else
		self->cells = cell;
	self->last = cell;
	self->count++;
}

void LinkedList_prepend(struct LinkedList *self, void *value)
{
	struct ListCell *cell = ListCell_new(value);
	ListCell_set_next(cell, self->cells);
	self->cells = cell;
	if(self->last == NULL)
		self->last = cell;
	self->count++;
}
