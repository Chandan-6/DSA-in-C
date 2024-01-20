#include<stdio.h>
#include<stdlib.h>
// in this code position at zero is not working.
struct node{
	int data;
	struct node *link;
};

struct node* createnode(int value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed.\n");
		exit(1); // It's used to terminate the program
	}
	newnode->data=value;
	newnode->link=NULL;
	return newnode;
};

struct node* addpos(struct node *start, int pos, int value){
	struct node *temp, *p, *prev;
	p = start;
	if(pos == 0){
		// insertion at beginning
		temp = createnode(value);
		temp->link = start;
		start = temp;
		return start;
	}
	int i=0;
	while(i<pos-1 && p!=NULL){
		prev = p;
		p = p->link;
		i++;
	}
	
	if(p == NULL && i==pos){
		temp = createnode(value);
		temp->link = NULL;
		prev->link = temp;
		return start;
	}
	else if(p==NULL){
		printf("Position is out of bounds.\n");
		return start;
	}
	else{
		temp = createnode(value);
		temp->link = p->link;
		p->link = temp;
		return start;
	}
}

void print_ll(struct node *p){
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
	struct node *D = createnode(40);
	
	// connecting nodes
	start = A;
	A->link = B;
	B->link = C;
	C->link = D;
	D->link = NULL;
	
	int value,position;
	printf("Enter the position and value : ");
	scanf("%d %d",&position,&value);
	
	addpos(start,position,value);
	
	// print
	print_ll(start);
	return 0;
}
