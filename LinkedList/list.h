#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    size_t size;
} LinkedList;

/* Initialisiert eine leere Liste. */
void list_init(LinkedList *list);

/* Fuegt einen Wert vorne bzw. hinten ein. Gibt false bei einem Fehler zurueck. */
bool list_push_front(LinkedList *list, int value);
bool list_push_back(LinkedList *list, int value);

/* Entfernt das erste Vorkommen von value. Gibt true zurueck, wenn es gefunden wurde. */
bool list_remove(LinkedList *list, int value);

/* Prueft, ob value in der Liste vorkommt. */
bool list_contains(const LinkedList *list, int value);

/* Gibt die Liste auf stdout aus. */
void list_print(const LinkedList *list);

/* Liefert Anzahl der Elemente bzw. true, wenn die Liste leer ist. */
size_t list_size(const LinkedList *list);
bool list_is_empty(const LinkedList *list);

/* Gibt alle Listenknoten frei und setzt die Liste zurueck. */
void list_clear(LinkedList *list);

#endif /* LINKED_LIST_H */