#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max_size 100

struct node {
	char data;
	struct node *link;
};

int isempty(struct node *top){
	return (top == NULL);
}

struct node* createnode(char value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	newnode->data = value;
	newnode->link = NULL;
	return newnode;
}

struct node *push(struct node *top, char ele){
	struct node *temp = createnode(ele);
	temp->link = top;
	top = temp;
	return top;
}

char pop(struct node **top){  // here we're not returning "top" so it is necessary to use **top to modify top in main fn.
	if(isempty(*top)){
		printf("Underflow\n");
		exit(1);
	}
	
	struct node *temp = *top;
	char item = temp->data;
	*top = temp->link;
	free(temp);
	return item;
}

int match(char x, char y) {
    if ((x == '(' && y == ')') || (x == '[' && y == ']') || (x == '{' && y == '}')) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
	struct node *top;
	
	char str[Max_size];
	printf("Enter expression: ");
	fgets(str, Max_size, stdin);
	
	for(int i=0; i<strlen(str);i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			top = push(top, str[i]);
		}
		
		if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
			if(isempty(top)){
				printf("More right than left.\n");
				exit(1);
			}
			char elem = pop(&top);
			
			if(!match(elem,str[i])){
				printf("Invalid Expression.\n");
				exit(1);
			}
	}
}
	if (isempty(top)) {
        printf("Expression is balanced\n");
    } else {
        printf("Expression is not balanced\n");
    }
    return 0;
}
