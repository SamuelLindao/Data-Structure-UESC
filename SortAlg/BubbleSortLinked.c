//
// Created by lacer on 22/04/2025.
//

#include "BubbleSortLinked.h"

#include <stdio.h>

void Bubblesort(Node *head, Node *tail)
{
    if (head == tail || head == NULL) return;

    Node *current = head;
    Node *anterior = NULL;
    int trocou = 0;
    while(current != tail)
    {
        if (current->data > next->data)
        {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
            trocou = 1;
        }
        anterior = current;

        current = current->next;
    }
    if (trocou == 0) return;

    Bubblesort(current, anterior);
}

void BubblesortInterface(List *list)
{
    if (list->head == NULL) return;

    Node *trail = list->head;
    while(trail->next != NULL)
    {
        trail = trail->next;
    }
    Bubblesort(list->head, trail);
}

