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
	newnode->data = value;
	newnode->link = NULL;
	return newnode;
}

struct node* addatbeg(struct node *start, int value){
	struct node *temp = createnode(value);
	temp->link = start;
	start = temp;
	return start;
}

struct node* addatend(struct node *start, int value){
	struct node *p = start, *temp = createnode(value);
	
	if(start == NULL){
		return temp;
	}
	while(p->link!=NULL){
		p=p->link;
	}
	p->link = temp;
	return start;
}

struct node* create_linked_list(struct node *start){
	int n, value, i;
	printf("No.of nodes want to be created: ");
	scanf("%d",&n);
	// 1st node
	printf("Enter 0th element into 0th node: ");
	scanf("%d",&value);
	start = addatbeg(start,value); // insertion at beginning
	
	// next elements
	for(i=1;i<n;i++){
		printf("Enter %dth element into %dth node: ",i,i);
		scanf("%d",&value);
		start = addatend(start,value); // as after 1st node every next insertion node will be at end.
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
	struct node *start;
	start = create_linked_list(start);
	
	// print
	print_ll(start);
	return 0;
}
