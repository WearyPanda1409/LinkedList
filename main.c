#include <stdio.h>
#include "list.h"

int main(void) {
    List list;
    /*  now init the list  */
    list_init(&list);

    printf("Liste am Anfang:\n");
    list_print(&list);

    printf("\nPush:\n");

    list_push(&list, 30.3);
    list_push(&list, 20.4);
    list_push(&list, 10.3);
    list_append(&list, 9.1);

    list_print(&list);

    printf("\nAppend:\n");
}