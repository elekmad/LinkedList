/*
 * LinkedList.h
 *
 *  Created on: 6 nov. 2020
 *      Author: damien
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>

struct ListCell
{
	void *value;
	struct ListCell *next;
};

struct LinkedList
{
	struct ListCell *cells;
	struct ListCell *last;
	size_t count;
};

typedef struct LinkedList LinkedList;

size_t LinkedList_get_count(struct LinkedList *self);
void LinkedList_init(struct LinkedList *self);
void LinkedList_finalize(struct LinkedList *self);
void LinkedList_prepend(struct LinkedList *self, void *value);
void LinkedList_append(struct LinkedList *self, void *value);
void LinkedList_do_to_all(struct LinkedList *self, void (*func)(void*, void*), void *arg);

#endif /* LINKEDLIST_H_ */
