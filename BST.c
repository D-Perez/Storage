#include <stdio.h>
#include <stdlib.h>

#define COUNT 10


typedef struct Node Node;

struct Node {
  int data;
  Node* left;
  Node* right;
};

void print2DUtil(Node *root, int space);

void print2D(struct Node *root);

Node* createNode(int data) {
  Node* new = (Node *) calloc(1, sizeof(Node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void printNode(Node* node) {
  if(node != NULL) {
    printf("The node's value is %d\n", node->data);
  }
  return;
}

Node* insertBST(Node* root, int data) {
  if(root == NULL) {
    return createNode(data);
  } else if(root->data >= data) {
    root->left = insertBST(root->left, data);
  } else {
    root->right = insertBST(root->right, data);
  }
  return root;
}

Node* findMin(Node* root) {
  if(root == NULL) {
    return NULL;
  }else if(root->left != NULL) {
    return findMin(root->left);
  }
  return root;
}

Node* search(Node* root, int x) {
  if(root->data == x || root == NULL) {
    return root;
  } else if(x > root->data) {
    return search(root->right, x);
  } else {
    return search(root->left, x);
  }
}

Node* delete(Node* root, int x) {
  if(root == NULL) {
    return NULL;
  }
  if (x > root->data) {
    root->right = delete(root->right, x);
  } else if (x < root->data) {
    root->left = delete(root->left, x);
  } else {
    
    // No children
    if(root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    }
    
    // One child
    else if(root->left == NULL || root->right == NULL) {
      Node* temp;
      if(root->left == NULL) {
        temp = root->right;
      } else if (root->right == NULL) {
        temp = root->left;
      }
      free(root);
      return temp;
      
    // Two children
    } else {
      Node* temp = findMin(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }
  return root;
}

int main() {
  Node* BST = NULL;
  BST = insertBST(BST, 10);
  BST = insertBST(BST, 20);
  BST = insertBST(BST, 5);
  BST = insertBST(BST, 8);
  BST = insertBST(BST, 30);
  BST = insertBST(BST, 15);
  BST = insertBST(BST, 1);
  BST = insertBST(BST, 9);
  BST = insertBST(BST, 7);
  
  print2D(BST);
  
  delete(BST, 5);
  print2D(BST);
  delete(BST, 8);

  
  print2D(BST);
  
}



// Code from geeksforgeeks
void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
  
void print2D(Node *root)
{
   // Pass initial space count as 0
  printf("Start of BST\n");
   print2DUtil(root, 0);
  printf("End of BST\n\n");

}

// end code from geeksforgeeks
