#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

// creates node
struct node *createnode(int value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newnode->data = value;
	newnode->link = NULL;
	return newnode;
}

// add empty
struct node *add_empty(struct node *start, int value){
	struct node *temp = createnode(value);
	start = temp;
	return start;
}

// add begin
struct node *add_begin(struct node *start, int value){
	struct node *temp = createnode(value);
	temp->link = start;
	start = temp;
	return start;
}

// add end
struct node *add_end(struct node*start, int value){
	struct node *temp = createnode(value), *p = start;
	while(p->link!=NULL){
		p=p->link;
	}
	p->link = temp;
	return start;
}


// creates linked list
struct node *create_linked_list(struct node *start){
	int n; // no.of nodes
	printf("Enter the no.of nodes : ");
	scanf("%d",&n);
	
	int value; // 1st node
	printf("Enter the value of 1st node: ");
	scanf("%d",&value);
	start = add_empty(start,value);
	
	for(int i=1; i<n; i++){
		printf("Enter the value of %dth node : ",i);
		scanf("%d",&value);
		start = add_end(start,value);
	}
	return start;	
}

// Insert after
struct node *insertion_after(struct node *start, int value, int after){
	struct node *p = start, *temp = createnode(value);
	while(p->link!=NULL){
		if(p->data==after){
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p=p->link;
	}
	// if after node is last node
	if(p->link == NULL){
		start = add_end(start,value);
		return start;	
	}
	
}

// Insert before
struct node *insertion_before(struct node *start,int value, int before){
	// at beginning
	if(start->data==before){
		start = add_begin(start,value);
		return start;
	}
	else{
	// other nodes
	struct node *p = start, *temp = createnode(value);
	while(p!=NULL){
		if(p->link->data==before){
		temp->link = p->link;
		p->link = temp;
		return start;	
		}
		p=p->link;
	}
	}	
}

// Insertion at position
struct node *insertion_position(struct node *start, int value, int position){
	// at begin
	if(position == 0){
		start = add_begin(start,value);
		return start;
	}
	// other positions
	struct node *p = start, *temp = createnode(value),*prev;
	int i=0;
	while(i<position-1 && p!=NULL){
		prev = p;
		p=p->link;
		i++;	
	}
	if(p==NULL && i==position){
		prev->link = temp;
		return start;
	}
	else if(p==NULL){
		printf("Position is out of bounds.\n");
		return start;
	}
	else{
		temp->link = p->link;
		p->link = temp;
		return start;
	}
	
}

// prints
void print_ll(struct node *p){
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");
}

int main(){
	struct node *start; 
	int value;
	//creates linked list
	start = create_linked_list(start);
	printf("Linked list : ");
	print_ll(start);
	
	printf("\n");
	// insertion at begin
	printf("Enter the value for insert-begin: ");
	scanf("%d", &value);
	start = add_begin(start, value);
	printf("Linked-list--> insert begin : ");
	print_ll(start);
	
	printf("\n");
	// insertion at after
	printf("Enter the value for insert-after: ");
	scanf("%d", &value);
	int after;
	printf("Enter the data of the <<<-AFTER->>> node: ");
	scanf("%d", &after);
	start = insertion_after(start,value,after);
	printf("Linked-list--> insert after : ");
	print_ll(start);
	
	printf("\n");
	// insertion at before
	printf("Enter the value for insert-before: ");
	scanf("%d", &value);
	int before;
	printf("Enter the data of the <<<-BEFORE->>> node: ");
	scanf("%d", &before);
	start = insertion_before(start,value,before);
	printf("Linked-list--> insert before : ");
	print_ll(start);
	
	printf("\n");
	// insertion at position
	printf("Enter the value for insert-position: ");
	scanf("%d", &value);
	int position;
	printf("Enter the <<-position->>> : ");
	scanf("%d", &position);
	start = insertion_position(start,value,position);
	printf("Linked-list--> insert position : ");
	print_ll(start);
	return 0;
}
