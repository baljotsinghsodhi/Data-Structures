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

int find_min(struct Node* root) {
    if (root == NULL) {
        return -1; // Sentinel value for empty tree
    }
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int find_max(struct Node* root) {
    if (root == NULL) {
        return -1; // Sentinel value for empty tree
    }
    struct Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int main() {
    struct Node *root = NULL;
    // Example insertion
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Pre-filled BST: 20 30 40 50 60 70 80 (in-order)\n");

    int min_val = find_min(root);
    int max_val = find_max(root);

    if (min_val != -1) {
        printf("Minimum element in BST: %d\n", min_val);
        printf("Maximum element in BST: %d\n", max_val);
    } else {
        printf("BST is empty.\n");
    }
    
    return 0;
}
