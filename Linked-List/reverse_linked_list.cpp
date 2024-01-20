#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};


// creates node
struct node* createnode(int value){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newnode->data = value;
	newnode->link = NULL;
	return newnode;	
}

struct node* reverse(struct node *start){
	struct node *prev, *ptr, *next;
	prev = NULL;
	ptr = start;
	
	while(ptr!=NULL){
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

void print_ll(struct node* p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->link;
	}
}

int main(){
	struct node *start;
	struct node *A = createnode(10);
	struct node *B = createnode(20);
	struct node *C = createnode(30);
	
	start = A;
	A->link = B;
	B->link = C;
	C->link = NULL;
	
	start = reverse(start);
	print_ll(start);
	
	return 0;	
}
