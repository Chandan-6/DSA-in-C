#include<stdio.h>
#include<stdlib.h>

int item;
struct node{
	int data;
	struct node *link;
};

int isempty(struct node *top){
  return (top == NULL);
}

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

struct node *push(struct node *top, int ele){
	struct node *temp = createnode(ele);
	temp->link = top;
	top = temp;
	return top;
}

int pop(struct node **top){
	if(isempty(*top)){
		printf("Underflow\n");
		exit(1);
	}
	struct node *temp = *top;
	item = temp->data;
  	*top = temp->link;
	free(temp);
	return item;
}

void display(struct node *top){
  struct node *p = top;
  printf("Stack linked list: ");
  while(p!=NULL){
    printf("%d\t",p->data);
    p=p->link;
  }
  printf("\n");
}

int main(){
	struct node *top = NULL;
	  int choice,data;
	  
	  while(1){
	    printf("Enter choice (1: PUSH, 2: POP, 3: display, 4: EXIT) : ");
	    scanf("%d", &choice);
	
	    switch(choice){
	
	      case 1:
	        printf("Enter data of pushing element: ");
	        scanf("%d", &data);
	        top = push(top, data);
	        break;
	
	      case 2: 
	        printf("Popped item: %d\n",pop(&top));
	        break;
	
	      case 3: 
	        display(top);
	        break;
	
	      case 4:
	        exit(0);
	
	      default:
	        printf("Invalid choice.\n");
	    }
	  }
  return 0;
}
