#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void list_init(List *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_push(List *list, double value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        return;
    }

    new_node->data = value;
    new_node->next = list->head;

    list->head = new_node;

    if (list->tail == NULL) {
        list->tail = new_node;
    }

    list->size++;
}

void list_append(List *list, double value)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (list->tail == NULL) {
        /* Liste ist leer */
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
}

int list_pop(List *list, double *value)
{
    if (list->head == NULL) {
        return 0;
    }

    Node *old_head = list->head;

    if (value != NULL) {
        *value = old_head->data;
    }

    list->head = old_head->next;

    if (list->head == NULL) {
        list->tail = NULL;
    }

    free(old_head);
    list->size--;

    return 1;
}

int list_pop_back(List *list, double *value)
{
    if (list->head == NULL) {
        return 0;
    }

    Node *current = list->head;

    /* Nur ein Element */
    if (current->next == NULL) {
        if (value != NULL) {
            *value = current->data;
        }

        free(current);

        list->head = NULL;
        list->tail = NULL;
        list->size--;

        return 1;
    }

    /* Zum vorletzten Element laufen */
    while (current->next != list->tail) {
        current = current->next;
    }

    if (value != NULL) {
        *value = list->tail->data;
    }

    free(list->tail);

    list->tail = current;
    list->tail->next = NULL;

    list->size--;

    return 1;
}

int list_insert(List *list, size_t index, double value)
{
    if (index > list->size) {
        return 0;
    }

    /* Am Anfang */
    if (index == 0) {
        list_push(list, value);
        return 1;
    }

    /* Am Ende */
    if (index == list->size) {
        list_append(list, value);
        return 1;
    }

    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        return 0;
    }

    Node *current = list->head;

    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;

    list->size++;

    return 1;
}

int list_remove(List *list, size_t index, double *value)
{
    if (index >= list->size || list->head == NULL) {
        return 0;
    }

    /* Erstes Element */
    if (index == 0) {
        return list_pop(list, value);
    }

    Node *current = list->head;

    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }

    Node *to_remove = current->next;

    if (value != NULL) {
        *value = to_remove->data;
    }

    current->next = to_remove->next;

    if (to_remove == list->tail) {
        list->tail = current;
    }

    free(to_remove);
    list->size--;

    return 1;
}

int list_get(const List *list, size_t index, double *value)
{
    if (index >= list->size || value == NULL) {
        return 0;
    }

    Node *current = list->head;

    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }

    *value = current->data;

    return 1;
}

size_t list_size(const List *list)
{
    return list->size;
}

int list_is_empty(const List *list)
{
    return list->head == NULL;
}

void list_clear(List *list)
{
    Node *current = list->head;

    while (current != NULL) {
        Node *next = current->next;

        free(current);

        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_print(const List *list)
{
    Node *current = list->head;

    printf("[");

    while (current != NULL) {
        printf("%lf", current->data);

        if (current->next != NULL) {
            printf(" -> ");
        }

        current = current->next;
    }

    printf("]\n");
}