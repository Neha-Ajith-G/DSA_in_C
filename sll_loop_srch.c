#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start;
void traverse()
{
    int i = 1;
    if (start != NULL)
    {
        struct node *curr = start;
        while (curr != NULL)
        {
            printf("%d)%d ", i, curr->data);
            curr = curr->link;
            i++;
        }
    }
}
void create()
{
    if (start == NULL)
    {
        int n, i;
        struct node *curr, *prev;
        curr = malloc(sizeof(struct node));
        curr->data = 1;
        printf("how many nodes do u want: ");
        scanf("%d", &n);
        start = curr;
        for (i = 2; i < n + 1; i++)
        {
            prev = curr;
            curr = malloc(sizeof(struct node));
            curr->data = i;
            prev->link = curr;
        }
        curr->link = NULL;
        traverse();
    }
}

void create_circular_link_list() {
    struct node *temp = start;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = start;
}
int detect_loop(struct node *start) {
    struct node *slow_ptr = start, *fast_ptr = start;

    while (slow_ptr && fast_ptr && fast_ptr->link) {
        slow_ptr = slow_ptr->link;
        fast_ptr = fast_ptr->link->link;
        if (slow_ptr == fast_ptr) {
            return 1;
        }
    }
    return 0;
}

int main(){
  create();
  int loopExists = detect_loop(start);
  if(loopExists) {
    printf("Loop exists in the linked list\n");
  } else {
    printf("No loop exists in the linked list\n");
  }
  create_circular_link_list();
  loopExists = detect_loop(start);
  if(loopExists) {
    printf("Loop exists in the linked list\n");
  } 
  else {
    printf("No loop exists in the linked list\n");
  }
return 0;
}

