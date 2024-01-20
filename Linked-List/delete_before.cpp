#include <stdio.h>
#include <stdlib.h>
// incomplete code (not working)
struct node {
  int data;
  struct node *link;
};

// creates node
struct node *createnode(int value) {
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  if (newnode == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  newnode->data = value;
  newnode->link = NULL;
  return newnode;
}

// deletes node before element
struct node *delete_before(struct node *start, int before_ele) {

  if (start == NULL || start->link == NULL) {
    return start; // List is already empty
  }

  if (start->link->data == before_ele) { // if node is 1st node
    struct node *temp = start;
    start = start->link;
    free(temp);
    return start;
  }

  struct node *p = start;
  while (p->link->data!=before_ele){
    p = p->link;
  }
	struct node *temp = p->link;
	p->link = temp->link;
	free(temp);

    
  	return start;  
    
  }

// prints linked list
void print_ll(struct node *t) {
  while (t != NULL) {
    printf("%d ", t->data);
    t = t->link;
  }
}

int main() {
  struct node *start;
  struct node *A = createnode(10);
  struct node *B = createnode(20);
  struct node *C = createnode(30);
  struct node *D = createnode(40);

  start = A;
  A->link = B;
  B->link = C;
  C->link = D;
  D->link = NULL;

  start = delete_before(start, 30);
  printf("Updated list: ");
  print_ll(start);
  return 0;
}
