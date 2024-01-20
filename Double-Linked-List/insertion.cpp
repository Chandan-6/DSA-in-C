#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};

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

// Insertion at empty
struct node *insert_empty(struct node *start, int ele){
	struct node *temp = createnode(ele);
	start = temp;
	return start;
}

// Insertion at begin
struct node *insert_begin(struct node *start, int ele){
	struct node *temp = createnode(ele);
	temp->next = start; // stores the 1st node address
	start->prev = temp; // 1st node prev stores the address of temp
	start = temp;
	return start;
}

// Insertion at end
struct node *insert_end(struct node *start, int ele){
	struct node *p = start, *temp = createnode(ele);
	while(p->next!=NULL){
		p=p->next;
	}
	p->next = temp;
	temp->prev = p;
	return start;
}

// Insertion after
struct node *insert_after(struct node *start, int after,int ele){
		
	// if node is empty
	if(start == NULL){
		return start;
	}
	
	struct node *temp = createnode(ele), *p = start;
	while(p!=NULL && p->data!=after){
		p=p->next;
	}
	temp->prev = p;
	temp->next = p->next;
	if(p->next!=NULL){
		p->next->prev = temp;
	}
	p->next = temp;
	return start;
}

// Insertion before
struct node *insert_before(struct node *start, int before,int ele){
	
	//if insertion at beginning
	if(start->data==before){
		start = insert_begin(start,ele);
		return start;
	}
	
	struct node *q = start->next, *temp = createnode(ele);
	while(q!=NULL){
		if(q->data==before){
			temp->prev = q->prev;
			temp->next = q;
			q->prev->next = temp;
			q->prev = temp;
		}
		q = q->next;
	}
	return start;
}

print_dll(struct node *p){
	printf("Double linked list : ");
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n\n");
}

int main(){
	struct node *start;
	
	//insertion at empty
	int value;
	printf("Enter value of 1st node (insert-empty) : ");
	scanf("%d",&value);
	start = insert_empty(start,value);
	print_dll(start);
	
	//insertion at beginning
	printf("Enter value of 2nd node (insert-begin): ");
	scanf("%d",&value);
	start = insert_begin(start,value);
	print_dll(start);
	
	//insertion at end
	printf("Enter value of 3rd node (insert-end): ");
	scanf("%d",&value);
	start = insert_end(start,value);
	print_dll(start);
	
	//insertion in between (AFTER)
	int after_ele;
	printf("Enter after element : ");
	scanf("%d",&after_ele);
	printf("Enter value of insertion node (insert-after): ");
	scanf("%d",&value);
	start = insert_after(start,after_ele,value);
	print_dll(start);
	
	//insertion in between (BEFORE)
	int before_ele;
	printf("Enter before element : ");
	scanf("%d",&before_ele);
	printf("Enter value of insertion node (insert-before): ");
	scanf("%d",&value);
	start = insert_before(start,before_ele,value);
	print_dll(start);
	return 0;
}
