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

#endif /* LINKEDLIST_H_ */
