#include <LinkedList.h>
#include <string.h>
#include <stdio.h>

#define CHAR_STRING_TEST "foobar"
#define CHAR_STRING_TEST2 "foobar2"
#define CHAR_STRING_TEST3 "foobar3"

#define CHAR_DATA "coincoin"

void func(char *data, char *data2)
{
    printf("%s %s\n", data, data2);
}

void func2(char *data)
{
    printf("%s\n", data);
}

int main(int argc, char **argv)
{
    int ret = 0;
    LinkedList s;
    LinkedList_init(&s);
    LinkedList_append(&s, CHAR_STRING_TEST);
    LinkedList_append(&s, CHAR_STRING_TEST2);
    LinkedList_append(&s, CHAR_STRING_TEST3);
    if(LinkedList_get_count(&s) != 3)
    {
        ret = -1;
        fprintf(stderr, "count does not match : %zu <> %d\n", LinkedList_get_count(&s), 3);
    }
    LinkedList_do_to_all(&s, (void(*)(void*, void*))func, (void*)CHAR_DATA);
    LinkedList_do_to_all(&s, (void(*)(void*, void*))func2, NULL);
    LinkedList_finalize(&s);
    return ret;
}
