
#include <stdio.h>
#include "list.h"

int main(void)
{
    List list;
    double value;

    list_init(&list);

    printf("Liste am Anfang:\n");
    list_print(&list);

    printf("\nPush:\n");

    if (!list_push(&list, 30.3) ||
        !list_push(&list, 20.4) ||
        !list_push(&list, 10.3)) {
        printf("Speicherfehler!\n");
        list_clear(&list);
        return 1;
        }

    printf("Append:\n");

    if (!list_append(&list, 9.1)) {
        printf("Speicherfehler!\n");
        list_clear(&list);
        return 1;
    }

    list_print(&list);

    printf("\nAnzahl: %d\n", list_size(&list));

    printf("\nElement an Index 1:\n");

    if (list_get(&list, 1, &value)) {
        printf("%g\n", value);
    }

    printf("\nElement einfuegen:\n");
    list_insert(&list, 2, 15.5);
    list_print(&list);

    printf("\nLetztes Element entfernen:\n");

    if (list_pop_back(&list, &value)) {
        printf("Entfernt: %g\n", value);
    }

    list_print(&list);

    printf("\nErstes Element entfernen:\n");

    if (list_pop(&list, &value)) {
        printf("Entfernt: %g\n", value);
    }

    list_print(&list);

    printf("\nListe leeren:\n");
    list_clear(&list);
    list_print(&list);

    printf("Leer: %d\n", list_is_empty(&list));

    return 0;
}