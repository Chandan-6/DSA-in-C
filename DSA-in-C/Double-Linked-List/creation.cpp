#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

// create node
struct node *createnode(int value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newnode->data = value;
	newnode->prev = NULL;
	newnode->next = NULL;
	return newnode;
}

// ADD EMPTY
struct node *add_empty(struct node *start, int ele){
	struct node *temp = createnode(ele);
	start = temp;
	return start;
}


// ADD END
struct node *add_end(struct node *start, int ele){
	struct node *temp = createnode(ele), *p = start;
	while(p->next!=NULL){
		p=p->next;
	}
	temp->prev = p;
	p->next = temp;
	return start;
}



// create double linked list
struct node *create_double_linked_list(struct node *start){
	int i,n,value;
	printf("Enter no.of nodes : ");
	scanf("%d",&n);
	
	printf("Enter the value of 1st node: ");
	scanf("%d",&value);
	//add empty
	start = add_empty(start,value);
	
	// next nodes
	for(i=1;i<n;i++){
		printf("Enter the value of %d node: ",i);
		scanf("%d",&value);
		start = add_end(start,value);		
	}
	return start;
}

void print_dll(struct node *p){
	printf("Double linked list : ");
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
}


int main(){
	struct node *start;
	start = create_double_linked_list(start);
	print_dll(start);
	return 0;
}










