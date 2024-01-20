#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// ---Logic---
/*
1. enqueue: new element should be inserted in stack-1 at the top
2. dequeue: pop elements from stack-1 & push those to stack-2 and dequeue the
top of stack-2, similary for front.
*/

int stack1[MAX], stack2[MAX];
int top_stack1 = -1, top_stack2 = -1;

int isfull_stack1(){ return(top_stack1 == MAX-1); }

int isfull_stack2(){ return(top_stack2 == MAX-1); }

int isempty_stack1(){ return(top_stack1 == -1); }

int isempty_stack2(){ return(top_stack2 == -1); }

// enqueuees stack-1 to stack-2
void stack1_to_stack2(){
	while(!isempty_stack1()){
			stack2[++top_stack2] = stack1[top_stack1--];
		}
}

// pushes stack-2 to stack-1
void stack2_to_stack1(){
	while(!isempty_stack2()){
			stack1[++top_stack1] = stack2[top_stack2--];
		}
}


void enqueue(int item){
	if(isfull_stack1() && isfull_stack2()){
		printf("Overflow.\n");
		exit(1);
	}
	else if(isempty_stack1() && !isempty_stack2()){
		stack2_to_stack1();
	}
	// enqueue(insertion) in stack1
	stack1[++top_stack1] = item;
}

int dequeue(){
	int del_item;
	if(isempty_stack2()){
		if(isempty_stack1()){
			printf("Underflow.\n");
			exit(1);
		}
		stack1_to_stack2(); // Move elements from stack1 to stack2
	}
	del_item = stack2[top_stack2--];
	// pushing back to stack-1
	if(isempty_stack1() && !isempty_stack2()){
		stack2_to_stack1();
	}
	return del_item;
}


int front(){
	int front_item;
	if(isempty_stack1() && isempty_stack2()){
		printf("Stack is empty.\n");
		exit(1);
	}
	
	else if(!isempty_stack1() && isempty_stack2()){
		stack1_to_stack2();
	}
	front_item = stack2[top_stack2];
	
	stack2_to_stack1();
	return front_item;
}

void display(){
	if(isempty_stack1() && isempty_stack2()){
		printf("Queue is already empty.\n");
		exit(1);
	}
	else if(isempty_stack2() && !isempty_stack1()){
		stack1_to_stack2();
		
		for(int i = top_stack2; i>=0; i--){
			printf("%d ",stack2[i]);
		}printf("\n");
	}
}

int main(){
	int choice, item;
	
	while(1){
		printf("Enter choice (1. Enqueue, 2. Dequeue, 3. Front, 4. Display, 5. EXIT): ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter value of item: ");
				scanf("%d", &item);
				enqueue(item);
				break;
				
			case 2:
				printf("Deleted item: %d\n", dequeue());
				break;
				
			case 3:
				printf("Peek Element is : %d\n", front());
				break;
				
			case 4:
				printf("\nQueue Item are : ");
				display();
				break;
			case 5:
				exit(0);
				
			default:
				printf("Invalid Choice.\n");
		}
	}
	return 0;
}

