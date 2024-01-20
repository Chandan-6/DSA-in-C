#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *link;
};

void printlinkedlist(struct node *p) {
  printf("Information of linked list are : ");
  while (p != NULL) {
    printf("%d ", p->value);
    p = p->link;
  }
}

int main() {
  int data;
  printf("Enter the value you wanted to inserted in: ");
  scanf("%d", &data);

  // intializing nodes
  struct node *start;
  struct node *temp = NULL;

  // alocating memory
  temp = (struct node *)malloc(sizeof(struct node));

  // assingning values
//  start = NULL;
  temp->value = data;

  // connecting nodes
  start = temp;
  temp->link = NULL;

  // printing linked list
  printlinkedlist(start);
  return 0;
}
