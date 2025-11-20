#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ALPHABET_SIZE 26

// The Trie node structure
struct TrieNode {
    // Array of pointers to the next 26 possible characters (a-z)
    struct TrieNode *children[ALPHABET_SIZE];
    // Flag to mark if this node is the end of a complete word
    bool isEndOfWord;
};

// Function to create a new Trie node
struct TrieNode* createNode() {
    struct TrieNode *newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    if (newNode) {
        newNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

// Global root pointer
struct TrieNode *root = NULL;

// Function to insert a word into the Trie
void insert() {
    char key[100];
    printf("Enter word to insert (lowercase a-z): ");
    scanf("%s", key);
    
    struct TrieNode *current = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            // If path doesn't exist, create a new node
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    // Mark the last node as the end of a complete word
    current->isEndOfWord = true;
    printf("Inserted: %s\n", key);
}

// Function to search for a word in the Trie
bool search() {
    char key[100];
    printf("Enter word to search: ");
    scanf("%s", key);
    
    struct TrieNode *current = root;
    for (int i = 0; i < strlen(key); i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    // Return true only if we reached a non-NULL node AND it marks the end of a word
    return (current != NULL && current->isEndOfWord);
}

// Function to check if any word starts with the given prefix
bool startsWith() {
    char prefix[100];
    printf("Enter prefix to check: ");
    scanf("%s", prefix);

    struct TrieNode *current = root;
    for (int i = 0; i < strlen(prefix); i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    // Return true if we reached a non-NULL node (it means the prefix exists)
    return (current != NULL);
}

int main() {
    root = createNode();
    int choice;
    
    do {
        printf("\n--- Trie Menu ---\n");
        printf("1. Insert Word\n2. Search Word\n3. Check Prefix\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                if (search()) {
                    printf("Word is FOUND in the Trie.\n");
                } else {
                    printf("Word is NOT found in the Trie.\n");
                }
                break;
            case 3:
                if (startsWith()) {
                    printf("Prefix is FOUND in the Trie (A word starts with this prefix).\n");
                } else {
                    printf("Prefix is NOT found in the Trie.\n");
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
