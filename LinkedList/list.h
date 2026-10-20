#ifndef LIST_H
#define LIST_H

typedef struct Node {
    double data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;

/* Initialisierung */
void list_init(List *list);

/* Elemente hinzufügen */
int list_push(List *list, double value);
int list_append(List *list, double value);

/* Elemente entfernen */
int list_pop(List *list, double *value);
int list_pop_back(List *list, double *value);

/* Elemente an einer Position bearbeiten */
int list_insert(List *list, int index, double value);
int list_remove(List *list, int index, double *value);
int list_get(const List *list, int index, double *value);

/* Informationen und Verwaltung */
int list_size(const List *list);
int list_is_empty(const List *list);
void list_clear(List *list);
void list_print(const List *list);

#endif