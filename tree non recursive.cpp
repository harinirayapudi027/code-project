#include <stdio.h> 
#include <stdlib.h> 
// Node structure 
struct Node { 
int data; 
struct Node* left; 
struct Node* right; 
}; 
// Stack node structure 
struct StackNode { 
struct Node* treeNode; 
struct StackNode* next; 
}; 
// Stack operations 
void push(struct StackNode** top, struct Node* treeNode) { 
struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
newNode->treeNode = treeNode; 
newNode->next = *top; 
*top = newNode; 
} 
struct Node* pop(struct StackNode** top) { 
if (*top == NULL) 
return NULL; 
struct StackNode* temp = *top; 
*top = (*top)->next; 
struct Node* popped = temp->treeNode; 
free(temp); 
return popped; 
} 
int isEmpty(struct StackNode* top) { 
return top == NULL; 
} 
// Create a new tree node 
struct Node* newNode(int data) { 
struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
node->data = data; 
node->left = node->right = NULL; 
return node; 
} 
// Non-recursive Inorder Traversal 
void inorder(struct Node* root) { 
struct StackNode* stack = NULL; 
struct Node* curr = root; 
printf("Inorder: "); 
while (curr != NULL || !isEmpty(stack)) { 
while (curr != NULL) { 
push(&stack, curr); 
curr = curr->left; 
} 
curr = pop(&stack); 
printf("%d ", curr->data); 
curr = curr->right; 
} 
printf("\n"); 
} 
// Non-recursive Preorder Traversal 
void preorder(struct Node* root) { 
if (root == NULL) return; 
struct StackNode* stack = NULL; 
push(&stack, root); 
printf("Preorder: "); 
while (!isEmpty(stack)) { 
struct Node* node = pop(&stack); 
printf("%d ", node->data); 
if (node->right) push(&stack, node->right); 
if (node->left) push(&stack, node->left); 
} 
printf("\n"); 
} 
// Non-recursive Postorder Traversal using two stacks 
void postorder(struct Node* root) { 
if (root == NULL) return; 
struct StackNode *stack1 = NULL, *stack2 = NULL; 
push(&stack1, root); 
printf("Postorder: "); 
while (!isEmpty(stack1)) { 
struct Node* node = pop(&stack1); 
push(&stack2, node); 
if (node->left) push(&stack1, node->left); 
if (node->right) push(&stack1, node->right); 
} 
while (!isEmpty(stack2)) { 
struct Node* node = pop(&stack2);
printf("%d ", node->data); 
} 
printf("\n"); 
} 
// Main function 
int main() { 
// Sample Tree: 
struct Node* root = newNode(1); 
root->left = newNode(2); 
root->right = newNode(3); 
root->left->left = newNode(4); 
root->left->right = newNode(5); 
root->right->left = newNode(6); 
root->right->right = newNode(7); 
inorder(root); 
preorder(root); 
postorder(root);
return 0; 
}
