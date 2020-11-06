/*
 * LinkedList.c
 *
 *  Created on: 6 nov. 2020
 *      Author: damien
 */


#include "LinkedList.h"
#include <malloc.h>
#include <string.h>

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

void LinkedList_finalize(struct LinkedList *self)
{
	if(self->cells != NULL)
		ListCell_free(self->cells);
}

void LinkedList_append(struct LinkedList *self, void *value)
{
	struct ListCell *cell = ListCell_new(value);
	if(self->last != NULL)
		ListCell_set_next(self->last, cell);
	self->last = cell;
}

void LinkedList_prepend(struct LinkedList *self, void *value)
{
	struct ListCell *cell = ListCell_new(value);
	ListCell_set_next(cell, self->cells);
	if(self->last == NULL)
		self->last = cell;
}
