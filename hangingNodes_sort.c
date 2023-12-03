#include <stdio.h>
#include <stdlib.h>

// LINK LIST WITH HANGING NODES
//  IDENTIFICATION OF HANGING NODES AND CONVERTION TO SORTED SINGLE CHAIN

struct Node {
  int data;
  struct Node *next;
  struct Node *link;
};

struct Node *head = NULL;
struct Node *second = NULL;
struct Node *third = NULL;
struct Node *sec_one = NULL;
struct Node *sec_two = NULL;

void traverse() {
  // Print the linked list
  struct Node *ptr = head;
  struct Node *ptr1 = sec_one;
  int count = 0;
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    ptr = ptr->next;
    count++;
    if (count == 2) {
      while (ptr1 != NULL) {
        printf(" %d-> ", ptr1->data);
        ptr1 = ptr1->link;
      }
      printf("NULL \t");
    }
  }
  printf("NULL\n");
}

void print_sorted() {
  struct Node *ptr = head;
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    ptr = ptr->next;
  }
  printf("NULL\n");
}

void conv_linear() {
  struct Node *ptr = head;
  while (ptr != NULL) {
    if (ptr->link != NULL) {
      struct Node *hangingNode = ptr->link;
      ptr->link = NULL; // Remove the hanging node from the main chain
      while (hangingNode != NULL) {
        struct Node *currentNode = head; // Start comparison from the beginning
        struct Node *prevNode = NULL;
        while (currentNode != NULL && currentNode->data < hangingNode->data) {
          prevNode = currentNode;
          currentNode = currentNode->next;
        }
        if (prevNode == NULL) {
          hangingNode->next = head;
          head = hangingNode; // Insert at the beginning of the main chain
        } else {
          hangingNode->next = prevNode->next;
          prevNode->next =
              hangingNode; // Insert at the correct position in the main chain
        }
        hangingNode = hangingNode->link; // Move to the next hanging node
      }
    }
    ptr = ptr->next;
  }
}

int main() {

  head = (struct Node *)malloc(sizeof(struct Node));
  second = (struct Node *)malloc(sizeof(struct Node));
  third = (struct Node *)malloc(sizeof(struct Node));
  sec_one = (struct Node *)malloc(sizeof(struct Node));
  sec_two = (struct Node *)malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;
  head->link = NULL;

  second->data = 8;
  second->next = third;
  second->link = sec_one;

  sec_one->data = 7;
  sec_one->link = sec_two;
  sec_one->next = NULL;

  sec_two->data = 6;
  sec_two->link = NULL;
  sec_two->next = NULL;

  third->data = 9;
  third->next = NULL;
  third->link = NULL;

  traverse();
  conv_linear();
  print_sorted();

  return 0;
}
