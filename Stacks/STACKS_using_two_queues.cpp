#include<stdio.h>
#include<stdlib.h>
#define MAX 10

/* --- Logic ---
Q1 - Queue-1, Q2 - Queue-2
1. To 'push' element, normally add it to Q1
2. To 'pop' element, normally pop and push the all elements from Q1 to Q2 except last element in Q1.
3. Store and return the last element in Q1.
4. Now Swaps the names of the Q1 & Q2.
*/

int Q1[MAX], Q2[MAX];
int  front_Q1 = -1, front_Q2 = -1;
int rear_Q1 = -1,  rear_Q2 = -1;

int isfull_Q1(){ return (rear_Q1 == MAX-1); }

int isempty_Q1(){ return (front_Q1 == -1 || front_Q1 == rear_Q1+1); }

int isfull_Q2(){ return (rear_Q2 == MAX-1); }

int isempty_Q2(){ return (front_Q2 == -1 || front_Q2 == rear_Q2+1); }


void swapQueues(int* q1, int* q2, int* front1, int* front2, int* rear1, int* rear2) {
    int* tempQ = q1;
    q1 = q2;
    q2 = tempQ;
    
    int tempFront = *front1;
    *front1 = *front2;
    *front2 = tempFront;
    
    int tempRear = *rear1;
    *rear1 = *rear2;
    *rear2 = tempRear;
}

void push(int item){
	if(isfull_Q1()){
		if(isfull_Q2()){
			printf("Stack is already full.\n");
			exit(1);
		}
		printf("Overflow.\n");
		exit(1);
	}
	
	if(front_Q1 == -1){
		front_Q1 = rear_Q1 = 0;
		Q1[rear_Q1] = item;
		return;
	}
	
	Q1[++rear_Q1] = item;
	return;
}

int pop() {
    if (isempty_Q1()) {
        printf("Stack is empty.\n");
        exit(1);
    }

    int del_item;

    if (front_Q1 == rear_Q1) {
        // If there's only one element in Q1, pop it
        del_item = Q1[front_Q1];
        front_Q1 = rear_Q1 = -1;
    } 
	else {
        // Move elements from Q1 to Q2, except the last element
        while (front_Q1 < rear_Q1) {
            Q2[++rear_Q2] = Q1[front_Q1++];
        }
        // Pop and retrieve the last element
        del_item = Q1[front_Q1];
        front_Q1 = rear_Q1 = -1;

        // Swap Q1 and Q2 
        swapQueues(Q1, Q2, &front_Q1, &front_Q2, &rear_Q1, &rear_Q2);
    }

    return del_item;
}



int peek(){
	
}

void display(){
	if(isempty_Q1() && isempty_Q2()){
		printf("Stack is already empty.\n");
		exit(1);
	}
	for(int i=front_Q1; i<=rear_Q1; i++){
		printf("%d ", Q1[i]);
	}
}

int main(){
	int choice, item;
	
	while(1){
		printf("Enter Choice (1. PUSH, 2. POP, 3. PEEK, 4. Display, 5. EXIT): ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter value of item: ");
				scanf("%d",&item);
				push(item);
				break;
				
			case 2:
				printf("Popped Element is %d\n",pop());
				break;
				
			case 3:
				printf("Peek Element is %d\n", peek());
				break;
				
			case 4:
				printf("\nStacks elements are : ");
				display();
				printf("\n");
				break;
			
			case 5:
				exit(0);
				
			default:
				printf("Invalid choice.\n");
		}
	}
	return 0;
}

