#include<stdio.h>
#include<stdlib.h>

struct node{   
    struct node *left;  
    int data; 
    struct node *right;  
};  
   
//Represent the root of binary tree  
struct node *root = NULL;  
   
//createNode() will create a new node  
struct node* createnode(int data){  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    //Assign data to newNode, set left and right child to NULL  
    newNode->data = data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
    return newNode;  
} 

struct node *insert(struct node *p, int ele){
	
	if(p == NULL){
		p = createnode(ele);
	}
	else if(ele < p->data){  // insertion in left subtree
		p->left = insert(p->left, ele);
	}
	else if(ele > p->data){
		p->right = insert(p->right, ele);
	}
	else{
		printf("\nDuplicate key.\n");
	}
	return p;
}

//inorder() will perform inorder traversal on binary search tree  
void inorderTraversal(struct node *node) {     // ---In-order-traversal---(recursive)
    //Check whether tree is empty  
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
    else {  
            
        if(node->left != NULL)  
            inorderTraversal(node->left);  
        printf("%d ", node->data);  
        if(node->right != NULL)  
            inorderTraversal(node->right);  
                
        }  
}

void postorderTraversal(struct node *node) {    // ---Post-order-traversal--- (recursive)
    //Check whether tree is empty  
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
    else {  
            
        if(node->left != NULL)  
            postorderTraversal(node->left);    
        if(node->right != NULL)  
            postorderTraversal(node->right);  
         
		printf("%d ", node->data);       
        }  
}

void preorderTraversal(struct node *node) {   // ---Pre-order-traversal---(recursive)
    //Check whether tree is empty  
    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
    else {  
        
        printf("%d ", node->data);
        
        if(node->left != NULL)  
            preorderTraversal(node->left);    
        if(node->right != NULL)  
            preorderTraversal(node->right);  
                
        }  
}

struct node *search(struct node *p, int ele){ // recursive
	if(p == NULL){
		printf("Key is not found.\n");
		return NULL;
	}
	else if(ele < p->data){
		return search(p->left, ele);
	}
	else if(ele > p->data){
		return search(p->right, ele);
	}
	else{
		return p;
	}
}

//-------------deletion--------

struct node *del_rec(struct node *p, int ele){
	struct node *temp, *succ;
	if(p == NULL){
		printf("\nElement is not found.\n");
		return p;
	}
	if(ele < p->data){
		p->left = del_rec(p->left,ele);
	}
	else if(ele > p->data){
		p->right = del_rec(p->right,ele);
	}
	else{
		if(p->left != NULL && p->right != NULL){ // 2 children
			succ = p->right;
			while(succ->left){
				succ = succ->left;
			}
			p->data = succ->data;
			p->right = del_rec(p->right, succ->data);
		}
		else{
			temp = p;
			if(p->left != NULL){ // 1 child
				p = p->left;
			}
			else if(p->right != NULL){ // 1 child
				p = p->right;
			}
			else{
				// only child
				p = NULL;
			}
			free(temp);
		}
	}
	return p;
}
    

	
int main(){
	int choice, ele;
	while(1){
		printf("\nEnter choice: (1: insert\n2: inorder traversal\n3: Postorder traversal\n4: preorder traversal\n5: Search\n6:Delete\n7: EXIT): ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Enter element data : ");
				scanf("%d",&ele);
				root = insert(root, ele);
				break;
				
			case 2:
				inorderTraversal(root);
				break;
			
			case 3:
				postorderTraversal(root);
				break;
				
			case 4:
				preorderTraversal(root);
				break;
			
			case 5:
				int sitem;
				printf("Enter Search element: ");
				scanf("%d",&sitem);
				if(search(root, sitem)){
					printf("\n%d is found.\n",sitem);
				}
				break;
			
			case 6:
				int del_ele;
				printf("Enter deleting element: ");
				scanf("%d",&del_ele);
				root = del_rec(root,del_ele);
				break;
						
			case 7:
				exit(0);
				
				
			default:
				printf("Invalid choice!!\n");
				exit(1);
		}
	}
	return 0;
} 
