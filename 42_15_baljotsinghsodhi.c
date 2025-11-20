#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// ... (create_node and insert functions from program 14 go here) ...
// For brevity, these are assumed to be included.

struct Node* create_node(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return create_node(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}
// -------------------------------------------------------------------

void print_range(struct Node* root, int low, int high) {
    if (root == NULL) return;

    // Search left subtree only if the root's data is greater than the low bound
    if (root->data > low) {
        print_range(root->left, low, high);
    }

    // Print data if it is within the range
    if (root->data >= low && root->data <= high) {
        printf("%d ", root->data);
    }

    // Search right subtree only if the root's data is smaller than the high bound
    if (root->data < high) {
        print_range(root->right, low, high);
    }
}

int main() {
    struct Node *root = NULL;
    int low, high;
    // Example insertion
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Pre-filled BST: 20 30 40 50 60 70 80 (in-order)\n");
    printf("Enter the low range (L): ");
    scanf("%d", &low);
    printf("Enter the high range (H): ");
    scanf("%d", &high);

    printf("Nodes in range [%d, %d]: ", low, high);
    print_range(root, low, high);
    printf("\n");
    
    return 0;
}
