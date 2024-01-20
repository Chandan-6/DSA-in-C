#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

// creates node
struct node *createnode(int value){
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newnode->data = value;
	newnode->link = NULL;
	return newnode;
}

// Add at empty
struct node *add_empty(struct node *last, int value){
	struct node *temp = createnode(value);
	last = temp;
	last->link = last;
	return last;
}

// Add at end
struct node *add_end(struct node *last, int value){
	struct node *temp = createnode(value);
	temp->link = last->link;
	last->link = temp;
	last = temp;
	return last;
}

struct node *create_circular_linked_list(struct node *last){
	int value;
	
	int n; // no.of nodes
	printf("Number of nodes: ");
	scanf("%d",&n);
	
	printf("Enter the value of 1st node: ");
	scanf("%d",&value);
	last = add_empty(last,value); // add at empty
	
	for(int i=1; i<n; i++){
		printf("Enter the value of %dth node: ",i);
		scanf("%d",&value);
		
		//struct node *temp;
		last = add_end(last,value);
	}
	return last;
	
}

// prints circular linked list
void print_cll(struct node *last){
	if(last == NULL){
		printf("Circular linked list is empty.\n");
		return;
	}
	struct node *p = last->link;
	do{
		printf("%d ",p->data);
		p = p->link;
	}while(p != last->link); // stops at when p again reached to first node
}



int main(){
	struct node *last;
	
	// creation of 
	last = create_circular_linked_list(last);
	
	print_cll(last);
	return 0;
}
