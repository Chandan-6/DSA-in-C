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

// Delete only node
struct node *del_only_node(struct node *start, int ele){
	struct node *temp;
	temp = start;
	start = NULL;
	free(temp);
	return start;
}

// Delete at begin
struct node *del_begin(struct node *start, int ele){
	struct node *temp;
	temp = start;
	start = temp->next;
	temp->next->prev = NULL; // start->prev = NULL
	free(temp);
	return start;
}



struct node *deletion(struct node *start, int ele){
	
	// when there is only one node
	if(start->next == NULL){
		if(start->data == ele){
			start = del_only_node(start, ele);
			return start;
		}
	}
	//when node is the 1st node
	if(start->data==ele){
		start = del_begin(start,ele);
			return start;
	}
	
	// between
	struct node *p =start->next;
	while(p->next!=NULL){
		if(p->data==ele){
			struct node *temp = p;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			return start;
		}
		p=p->next;
	}
	
	// at end
	if(p->data==ele && p->next==NULL){
		struct node *temp = p;
		temp->prev->next = NULL;
		free(temp);	
	}
	return start;
}



void print_dll(struct node *p){
		while(p!=NULL){
			printf("%d ",p->data);
			p=p->next;
		}
		printf("\n");
}


int main(){
	struct node *start;
	
	// Creation of double linked lists
	start = create_double_linked_list(start);
	printf("Double linked list : ");
	print_dll(start);
	
	// deletion
	int delete_ele;
	printf("Enter the element to be deleted: ");
	scanf("%d",&delete_ele);
	start = deletion(start,delete_ele);
	printf("Deleted linked list : ");
	print_dll(start);
	return 0;
}



