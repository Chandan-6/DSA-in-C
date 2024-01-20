#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack_array[MAX], top = -1;

int isfull(){
  return (top == MAX-1);
}

int isempty(){
  return (top == -1);
}

void push(int item){
    if(isfull()){
      printf("Overflow\n");
      return;
    }
  top++;
  stack_array[top] = item;
  }

int pop(){
  int x;
  if(isempty()){
    printf("Underflow\n");
    exit(1);
  }
  x = stack_array[top];
  top--;
  return x;
}

int peek(){
  if(isempty()){
    printf("underflow\n");
    exit(1);
  }
  return stack_array[top];
}

void display(){
  if(!isempty()){
    for(int i = top; i >= 0 ; i--){
      printf("%d ",stack_array[i]);
    }
    printf("\n");
  }
  else{
    printf("Stack is empty.\n");
  }
} 	

int main(){
  int choice,item;

  
  while(1){
      printf("Enter choice(1: PUSH, 2: POP, 3: PEEK, 4:Display, 5: exit): ");
      scanf("%d",&choice);
    
    switch(choice){
      case 1: 
        printf("Enter item to push: ");
        scanf("%d",&item);
        push(item);
        break;
      
      case 2:
        printf("Popped item: %d\n",pop());
        break;
      
      case 3: 
        printf("Peeked item: %d\n",peek());
        break;
      
      case 4: 
        display();
        break;

      case 5: 
        exit(0); // commonly used to indicate that the program ran without any errors or issues.
      
      default:
        printf("Invalid choice.\n");
    }
  }
  
}

