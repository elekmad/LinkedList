#include <LinkedList.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHAR_STRING_TEST "foobar"
#define CHAR_STRING_TEST2 "foobar2"
#define CHAR_STRING_TEST3 "foobar3"
#define CHAR_STRING_TEST4 "foobar4"

LinkedList s;

int test_one_el_remove_el(void)
{
    int ret = 0;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    if(LinkedList_get_count(&s) != 1)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_remove(&s, CHAR_STRING_TEST);
    if(LinkedList_get_count(&s) != 0)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_finalize(&s);
    return ret;
}

int test_two_el_remove_first_el(void)
{
    int ret = 0;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    LinkedList_append(&s, CHAR_STRING_TEST2);
    if(LinkedList_get_count(&s) != 2)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_remove(&s, CHAR_STRING_TEST);
    if(LinkedList_get_count(&s) != 1)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_finalize(&s);
    return ret;
}

int test_two_el_remove_last_el(void)
{
    int ret = 0;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    LinkedList_append(&s, CHAR_STRING_TEST2);
    if(LinkedList_get_count(&s) != 2)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_remove(&s, CHAR_STRING_TEST2);
    if(LinkedList_get_count(&s) != 1)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_finalize(&s);
    return ret;
}

int test_three_el_remove_first_el(void)
{
    int ret = 0;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    LinkedList_append(&s, CHAR_STRING_TEST2);
    LinkedList_append(&s, CHAR_STRING_TEST3);
    if(LinkedList_get_count(&s) != 3)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_remove(&s, CHAR_STRING_TEST);
    if(LinkedList_get_count(&s) != 2)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_finalize(&s);
    return ret;
}


int test_three_el_remove_middle_el(void)
{
    int ret = 0;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    LinkedList_append(&s, CHAR_STRING_TEST2);
    LinkedList_append(&s, CHAR_STRING_TEST3);
    if(LinkedList_get_count(&s) != 3)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_remove(&s, CHAR_STRING_TEST2);
    if(LinkedList_get_count(&s) != 2)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_finalize(&s);
    return ret;
}

int test_three_el_remove_last_el(void)
{
    int ret = 0;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    LinkedList_append(&s, CHAR_STRING_TEST2);
    LinkedList_append(&s, CHAR_STRING_TEST3);
    if(LinkedList_get_count(&s) != 3)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_remove(&s, CHAR_STRING_TEST3);
    if(LinkedList_get_count(&s) != 2)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_finalize(&s);
    return ret;
}

int test_three_el_remove_not_found(void)
{
    int ret = 0;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    LinkedList_append(&s, CHAR_STRING_TEST2);
    LinkedList_append(&s, CHAR_STRING_TEST3);
    if(LinkedList_get_count(&s) != 3)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_remove(&s, CHAR_STRING_TEST4);
    if(LinkedList_get_count(&s) != 3)
    {
        ret = 1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 1);
    }
    LinkedList_finalize(&s);
    return ret;
}



int main(int argc, char **argv)
{
    if(test_one_el_remove_el())
        exit(EXIT_FAILURE);

    if(test_two_el_remove_first_el())
        exit(EXIT_FAILURE);

    if(test_two_el_remove_last_el())
        exit(EXIT_FAILURE);

    if(test_three_el_remove_first_el())
        exit(EXIT_FAILURE);

    if(test_three_el_remove_middle_el())
        exit(EXIT_FAILURE);

    if(test_three_el_remove_last_el())
        exit(EXIT_FAILURE);

    if(test_three_el_remove_not_found())
        exit(EXIT_FAILURE);

    exit(EXIT_SUCCESS);
}
