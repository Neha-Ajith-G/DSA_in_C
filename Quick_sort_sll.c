#include <stdio.h>
#include <stdlib.h>

// QUICK SORT ON LINKED LIST

// Node structure for linked list
struct Node {
  int data;
  struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *current = NULL;

void traverse() {
  int i = 1;
  if (head != NULL) {
    current = head;
    while (current != NULL) {
      printf("NODE %d : %d \n", i, current->data);
      current = current->next;
      i++;
    }
  }
}

// Finding last node of linked list
struct Node *end_node(struct Node *head) {
  struct Node *temp = head;
  while (temp != NULL && temp->next != NULL) {
    temp = temp->next;
  }
  return temp;
}

void create(int n) {
  head = malloc(sizeof(struct Node));
  if (head != NULL) {
    struct Node *newNode = head;
    printf("data: \n");
    newNode->data = 4;
    newNode->next = NULL;
    tail = newNode;
    for (int i = 2; i <= n; i++) {
      newNode->next = malloc(sizeof(struct Node));
      newNode = newNode->next;
      newNode->data = 100 / i;
    }
    newNode->next = NULL;
    tail = newNode;
  }
  traverse();
}

void swap(struct Node *a, struct Node *b) {
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

struct Node *partition(struct Node *first, struct Node *last) {
  struct Node *pivot = first;
  struct Node *start = first;
  int temp = 0;
  while (start != NULL && start != last) {
    if (start->data < last->data) {
      pivot = first;
      swap(start, pivot); // Swap2

      first = first->next;
    }

    start = start->next;
  }
  // Change last node value to current node SWAP1
  swap(first, last);
  return pivot;
}

// Performing quick sort in  the given linked list
void quickSort(struct Node *first, struct Node *last) {
  if (first == last) {
    return;
  }
  struct Node *pivot = partition(first, last);

  if (pivot != NULL && pivot->next != NULL) {
    quickSort(pivot->next, last);
  }

  if (pivot != NULL && first != pivot) {
    quickSort(first, pivot);
  }
}

int main(void) {
  printf("Hello World\n");
  create(6);
  quickSort(head, end_node(head));
  printf("\n AFTER SORT: \n ");
  traverse();

  return 0;
}