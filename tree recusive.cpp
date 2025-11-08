#include <stdio.h> 
#include <stdlib.h> 
// Define a node structure 
struct Node { 
int data; 
struct Node* left; 
struct Node* right; 
}; 
// Function to create a new node 
struct Node* createNode(int data) { 
struct Node* newNode = (struct Node*) malloc(sizeof(struct Node)); 
if (newNode == NULL) { 
printf("Memory allocation failed!\n"); 
exit(1); 
} 
newNode->data = data; 
newNode->left = NULL; 
newNode->right = NULL; 
return newNode; 
} 
// Preorder Traversal: Root -> Left -> Right 
void preorderTraversal(struct Node* root) { 
if (root == NULL) return; 
printf("%d ", root->data); 
preorderTraversal(root->left); 
preorderTraversal(root->right); 
} 
// Inorder Traversal: Left -> Root -> Right 
void inorderTraversal(struct Node* root) { 
if (root == NULL) return; 
inorderTraversal(root->left); 
printf("%d ", root->data); 
inorderTraversal(root->right); 
} 
// Postorder Traversal: Left -> Right -> Root 
void postorderTraversal(struct Node* root) { 
if (root == NULL) return; 
postorderTraversal(root->left); 
postorderTraversal(root->right); 
printf("%d ", root->data); 
} 
// Main function 
int main() { 
struct Node* root = createNode(1); 
root->left = createNode(2); 
root->right= createNode(3); 
root->left->left = createNode(4); 
root->left->right = createNode(5); 
printf("Preorder traversal: "); 
preorderTraversal(root); 
printf("\n"); 
printf("Inorder traversal: "); 
inorderTraversal(root); 
printf("\n"); 
printf("Postorder traversal: "); 
postorderTraversal(root); 
printf("\n"); 
return 0; 
}
