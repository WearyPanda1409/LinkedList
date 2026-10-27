#include "list.h"

#include <stdio.h>

int main(void) {
    LinkedList list;
    list_init(&list);

    puts("Fuege Elemente hinzu:");
    if (!list_push_back(&list, 10) ||
        !list_push_back(&list, 20) ||
        !list_push_back(&list, 30) ||
        !list_push_front(&list, 5)) {
        fputs("Fehler: Speicher konnte nicht reserviert werden.\n", stderr);
        list_clear(&list);
        return 1;
        }
    list_print(&list);

    printf("Ist 20 enthalten? %s\n", list_contains(&list, 20) ? "Ja" : "Nein");
    printf("Ist 99 enthalten? %s\n", list_contains(&list, 99) ? "Ja" : "Nein");

    puts("\nEntferne den Wert 20:");
    if (!list_remove(&list, 20)) {
        puts("Wert 20 wurde nicht gefunden.");
    }
    list_print(&list);

    printf("Anzahl der Elemente: %zu\n", list_size(&list));
    printf("Ist die Liste leer? %s\n", list_is_empty(&list) ? "Ja" : "Nein");

    list_clear(&list);
    puts("\nNach list_clear:");
    list_print(&list);

    return 0;
}