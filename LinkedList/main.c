#include "list.h"

#include <stdio.h>

int main() {

    LinkedList list;
    ll_init(&list);

    puts("Fuege Elemente hinzu:");
    if (!ll_push_back(&list, 10) ||
        !ll_push_back(&list, 20) ||
        !ll_push_back(&list, 30) ||
        !ll_push_front(&list, 5)) {
        fputs("Fehler: Speicher konnte nicht reserviert werden.\n", stderr);
        ll_clear(&list);
        return 1;
        }
    ll_print(&list);

    printf("Ist 20 enthalten? %s\n", ll_contains(&list, 20) ? "Ja" : "Nein");
    printf("Ist 99 enthalten? %s\n", ll_contains(&list, 99) ? "Ja" : "Nein");

    puts("\nEntferne den Wert 20:");
    if (!ll_remove(&list, 20)) {
        puts("Wert 20 wurde nicht gefunden.");
    }
    ll_print(&list);

    printf("Anzahl der Elemente: %zu\n", ll_size(&list));
    printf("Ist die Liste leer? %s\n", ll_is_empty(&list) ? "Ja" : "Nein");

    ll_clear(&list);
    puts("\nNach list_clear:");
    ll_print(&list);

    return 0;
}