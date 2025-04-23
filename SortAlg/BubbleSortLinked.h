//
// Created by lacer on 22/04/2025.
//

#ifndef BUBBLESORTLINKED_H
#define BUBBLESORTLINKED_H

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct lista {
    Node *head;
    int size;
} List;

void Bubblesort(Node *head, Node *tail);
void BubblesortInterface(Node *head);

#endif //BUBBLESORTLINKED_H
