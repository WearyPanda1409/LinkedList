#include "list.h"

#include <stdio.h>
#include <stdlib.h>

void ll_init(LinkedList *list) {
    if (list == NULL) {
        return;
    }

    list->head = NULL;
    list->size = 0;
}

bool ll_push_front(LinkedList *list, double value) {
    if (list == NULL) {
        return false;
    }

    Node *node = malloc(sizeof(*node));
    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = list->head;
    list->head = node;
    list->size++;
    return true;
}

bool ll_push_back(LinkedList *list, double value) {
    if (list == NULL) {
        return false;
    }

    Node *node = malloc(sizeof(*node));
    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }

    list->size++;
    return true;
}

bool ll_remove(LinkedList *list, double value) {
    if (list == NULL) {
        return false;
    }

    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (current->value == value) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            list->size--;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

bool ll_contains(const LinkedList *list, double value) {
    if (list == NULL) {
        return false;
    }

    const Node *current = list->head;

    while (current != NULL) {
        if (current->value == value) {
            return true;
        }

        current = current->next;
    }

    return false;
}
void ll_print(const LinkedList *list) {
    const Node *current = list->head;

    while (current != NULL) {
        printf("%g ", current->value);
        current = current->next;
    }

    printf("\n");
}
void ll_clear(LinkedList *list) {
    Node *current = list->head;

    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    list->head = NULL;
    list->size = 0;
}

uint64_t ll_size(const LinkedList *list) {
    return list->size;
}

bool ll_is_empty(const LinkedList *list) {
    return list->head == NULL;
}