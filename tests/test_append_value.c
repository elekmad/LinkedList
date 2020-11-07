#include <LinkedList.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_STRING_TEST "foobar"

int main(int argc, char **argv)
{
    int ret = 0;
    LinkedList s;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    if(LinkedList_get_count(&s) != 1)
    {
        ret = -1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_append(&s, CHAR_STRING_TEST);
    if(LinkedList_get_count(&s) != 2)
    {
        ret = -1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 2);
    }
    fprintf(stderr, "All is right !\n");
    LinkedList_finalize(&s);
    if(ret == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);
}
