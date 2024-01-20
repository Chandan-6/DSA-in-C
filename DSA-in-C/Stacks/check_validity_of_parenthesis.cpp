#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_size 100
int stack_array[MAX_size], top = -1;

int isfull(){
	return (top == MAX_size-1);
}

int isempty(){
	return (top == -1);
}

void push(char item){
	if(isfull()){
		printf("Overflow\n");
		exit(1);
	}
	top++;
	stack_array[top] = item;
}

char pop(){
	char x;
	if(isempty()){
		printf("Underflow\n");
		exit(0);
	}
	x = stack_array[top];
	top--;
	return x;
}

int match(char x, char y) {
    if ((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}')) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
	char str[MAX_size];
	printf("Enter expression : ");
	fgets(str, MAX_size, stdin);
	
	
	for(int i=0; i<strlen(str);i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			push(str[i]);
		}
		
		if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
			if(isempty()){
				printf("More right than left.\n");
				exit(1);
			}
			char elem = pop();
			
			int r = match(elem,str[i]);
			if(r == 1){
				continue;
			}
			else{
				printf("Invalid Expression.\n");
				exit(1);
			}
		}
	}
	
	 if (isempty()) {
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }
	
	return 0;
}
