#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_size 100
char stack_array[Max_size];
int top = -1;

int isfull() {
  return (top == Max_size - 1);
}

int isempty() {
  return (top == -1);
}

void push(char item) {
  if (isfull()) {
    printf("Overflow\n");
    exit(1);
  }
  top++;
  stack_array[top] = item;
}

char pop() {
  char x;
  if (isempty()) {
    printf("Underflow\n");
    exit(0);
  }
  x = stack_array[top];
  top--;
  return x;
}

char peek() {
  if (isempty()) {
    printf("Underflow\n");
    exit(0);
  }
  return stack_array[top];
}

int match(char x, char y) {
  if ((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}')) {
    return 1;
  } else {
    return 0;
  }
}

int priority(char item) {
  if (item == '^') {
    return 1;
  } else if (item == '*' || item == '/' || item == '%') {
    return 2;
  } else if (item == '+' || item == '-') {
    return 3;
  }
  else{
    return 0;
  }
}

int main() {
  char infix[Max_size];
  printf("Enter INFIX: ");
  fgets(infix, Max_size, stdin);
  char postfix[Max_size];
  int postfix_index = 0;

  for (int i = 0; i < strlen(infix); i++) {

    // if found operand add to postfix exp
    if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9')) {
      postfix[postfix_index] = infix[i];
      postfix_index++;
    }


    // if 'left' parenthesis is found push it to stack
    else if (infix[i] == '(' || infix[i] == '[' || infix[i] == '{') {
      push(infix[i]);
    }

	// for 'right' parenthesis
    else if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}') {
      char closingBracket = infix[i];
      while (!isempty() && !match(peek(), closingBracket)) {
        char ele = pop();
        postfix[postfix_index] = ele;
        postfix_index++;
      }
      if (!isempty() && match(peek(), closingBracket)) {
        pop(); // Pop the matching opening bracket
      }
    } 
	
	
	else if (infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%' || infix[i] == '+' || infix[i] == '-') {
      while (!isempty() && (priority(peek()) != 0) && priority(peek()) <= priority(infix[i])) {
        char ele = pop();
        postfix[postfix_index] = ele;
        postfix_index++;
      }
      push(infix[i]);
    }
  }

  // Pop any remaining operators from the stack
  while (!isempty()) {
    char ele = pop();
    postfix[postfix_index] = ele;
    postfix_index++;
  }

  // Null-terminate the postfix expression
  postfix[postfix_index] = '\0';

  // Print the postfix expression
  printf("Postfix: %s\n", postfix);

  return 0;
}

