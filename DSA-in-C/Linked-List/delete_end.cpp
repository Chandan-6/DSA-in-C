#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node* createnode(int value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newnode->data=value;
	newnode->link=NULL;
	return newnode;
}

struct node* delete_end(struct node *start, int value){
	if(start==NULL){
		return NULL;
	}
	
	else if(start->link==NULL && start->data==value){
		free(start);
		return NULL; // when having only one node
	}
	
	struct node *p = start;
	while(p->link!=NULL){
		if(p->link->data==value){
			break;
		}
		p = p->link;
	}
	struct node *temp = p->link;
	p->link = temp->link;
	free(temp)
	return start;
}

void print_ll(struct node *t){
	while(t!=NULL){
		printf("%d ",t->data);
		t=t->link;
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
	
	delete_end(start,30);
	printf("Updated list: ");
	print_ll(start);
	return 0;
}












