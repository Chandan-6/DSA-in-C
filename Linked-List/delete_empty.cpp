#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node* delete_empty(struct node *start,int value){
	if (start == NULL) {
        return start; // List is already empty
    }

    // Check if the first node's data matches the specified value
    if (start->data == value) {
        struct node *temp = start;
        start = start->link;
        free(temp); // Delete the node
    }
    return start;
}

void print_ll(struct node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->link;
	}
}

int main(){
	struct node *start, *A;
	A = (struct node*)malloc(sizeof(struct node));
	A->data = 10;
	A->link = NULL;
	start = A;
	
	// fn for deletion of node
	start = delete_empty(start,10);
	printf("Updated list: ");
	print_ll(start);
}
