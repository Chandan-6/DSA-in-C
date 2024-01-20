#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define Max_size 100

int stack_array[Max_size],top = -1;

int isfull(){
	return (top == Max_size-1);
}

int isempty(){
	return (top == -1);
}

void push(int item){
	if(isfull()){
		printf("Overflow\n");
		exit(1);
	}
	top++;
	stack_array[top] = item;
}

int pop(){
	int x;
	if(isempty()){
		printf("Underflow\n");
		exit(0);
	}
	x = stack_array[top];
	top--;
	return x;
}

int main(){
	char str[Max_size];
	printf("Enter pre-fix expression: ");
	fgets(str, Max_size, stdin);
	int result = 0;
	
	for(int i=0; i<strlen(str); i++){
		
		// if found operand(0-9) push it into stack
		if(str[i] >= '0' && str[i] <= '9'){
			char n[2] = {str[i], '\0'};
			int num = atoi(n);
			push(num);
		}
		
		// if found the operator, use the operator for last two operators in stack.
		else if(str[i] == '^' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '+' ||str[i] == '-'){
			int B = pop();
			int A = pop();
			
			switch(str[i]){
				case '^':
					result = pow(A,B);
					push(result);
					break;
				case '*':
					result = A * B;
					push(result);
					break;
				case '/':
					result = A / B;
					push(result);
					break;
				case '%':
					result = A % B;
					push(result);
					break;
				case '+':
					result = A + B;
					push(result);
					break;
				case '-':
					result = A - B;
					push(result);
					break;
				 default:
		            printf("Error: Invalid operator!\n");
		            return 1; // Exit with an error code
			}
		}
	}
	
	printf("Result after evaluation: %d\n",result);
	return 0;
}
