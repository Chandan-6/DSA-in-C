#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *link;
};

struct node* createnode(int value){
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  if(newnode == NULL){
    printf("Memory allocation failed.\n");
    exit(1);
  }
  newnode->data = value;
  newnode->link = NULL;
  return newnode;
};

struct node* add_before(struct node *start, int value, int before_ele){
  struct node *temp, *p;
  temp = createnode(value);
  if(start==NULL){
  	return temp;
  }
  
  if(start->data==before_ele){  // insertion at beginning.
  	temp->link=start;
  	start = temp;
  	return start;
  }
  
  p = start;
  while(p->link!=NULL){
    if(p->link->data==before_ele){
      temp->link = p->link;
      p->link = temp;
      return start;
    }
    p=p->link;
  }
	printf("Element %d not found in the list.\n", before_ele);
    free(temp);
    return start;
  
};

void print_ll(struct node *p){
  while(p!=NULL){
    printf("%d ",p->data);
    p = p->link;
  }
}

int main(){
  struct node *start;
  struct node *A = createnode(10);
  struct node *B = createnode(20);
  struct node *C = createnode(40);
  struct node *D = createnode(50);

  // connecting nodes
  start = A;
  A->link = B;
  B->link = C;
  C->link = D;
  D->link = NULL;

  int value;
  printf("Enter the value of data : ");
  scanf("%d",&value);
  // insert before
  add_before(start,value,40);
  
  //print
  print_ll(start);

  return 0;
}
