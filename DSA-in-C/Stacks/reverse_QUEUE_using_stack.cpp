#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack_array[MAX], queue_array[MAX];
int top = -1, front = -1, rear = -1;


int isfull_stack(){
  return (top == MAX-1);
}

int isempty_stack(){
  return (top == -1);
}

int isfull_queue(){
	return (rear == MAX-1);
}		

int isempty_queue(){
	return (front == -1 || front == rear+1);
}

//---------------****--------------------------

void insert_queue(int ele){
	if(isfull_queue()){
		printf("Overflow.\n");
		return;
	}
	if(front == -1){
		front = rear = 0;
		queue_array[rear] = ele;
		return;
	}
	rear++;
	queue_array[rear] = ele;
	return;
}

void push_stack(int item){ // ---stack-pushing---
    if(isfull_stack()){
      printf("Overflow\n");
      return;
    }
  top++;
  stack_array[top] = item;
  }

void del(){ // ---deletion from Queue and pushing to stack
	int del_ele;
	if(isempty_queue()){
		printf("Underflow.\n");
		exit(1);
	}
	while(!isempty_queue()){
		del_ele = queue_array[front++];
		push_stack(del_ele);
	}
	return;
}

void pop(){  // popping from stack and inserting items to queue
  int x;
  if(isempty_stack()){
    printf("Underflow\n");
    exit(1);
  }
  while(!isempty_stack()){
 	x = stack_array[top--];
  	insert_queue(x);
  }
	return;
}

void display_queue(){
	if(isempty_queue()){
		printf("Underflow\n");
		exit(1);
	}
	for(int i=front; i <= rear; i++){
		printf("%d ",queue_array[i]);
	}printf("\n");	
}

//---------------****--------------------------


int main(){
	int n, item;
	// n = number of elements in stack to pushed
	
	printf("Enter n(no.of elements) : ");
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		printf("Enter value of %d item: ", i);
		scanf("%d",&item);
		insert_queue(item);
	}
	
	printf("Queue elements are: ");
	display_queue();
	
	
	// deleting the elements from the queue & pushing it to stack
	del();
	// popping from stack & inserting to queue
	pop();
	
	printf("Reversed Queue is : ");
	display_queue();
	
	return 0;
}
