#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

// --- Utility Functions ---

void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// --- Loop Detection (Floyd's Cycle) ---

bool detectLoop(struct Node *head) {
    if (head == NULL) return false;
    struct Node *slow = head;
    struct Node *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}


// --- Merge Sort Helper Functions ---

// Function to split the list into two halves
void frontBackSplit(struct Node *source, struct Node **frontRef, struct Node **backRef) {
    struct Node *fast;
    struct Node *slow;
    slow = source;
    fast = source->next;
    
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL; // Terminate the first half
}

// Function to merge two sorted lists
struct Node* sortedMerge(struct Node *a, struct Node *b) {
    struct Node *result = NULL;
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}

// The main function for Merge Sort
void mergeSort(struct Node **headRef) {
    struct Node *head = *headRef;
    struct Node *a, *b;
    
    if (head == NULL || head->next == NULL) {
        return;
    }

    frontBackSplit(head, &a, &b);
    
    mergeSort(&a);
    mergeSort(&b);
    
    *headRef = sortedMerge(a, b);
}

// --- Main Program ---

int main() {
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int choice, data;
    
    // Setup List 1 (unsorted)
    list1 = insertAtEnd(list1, 5);
    list1 = insertAtEnd(list1, 2);
    list1 = insertAtEnd(list1, 8);
    list1 = insertAtEnd(list1, 1);
    printf("Initial List 1: ");
    display(list1);

    // Setup List 2 (to be sorted and merged later)
    list2 = insertAtEnd(list2, 7);
    list2 = insertAtEnd(list2, 4);
    list2 = insertAtEnd(list2, 6);
    printf("Initial List 2: ");
    display(list2);

    do {
        printf("\n--- LL Advanced Menu ---\n");
        printf("1. Sort List 1 (Merge Sort)\n2. Detect Loop in List 1\n3. Merge Sorted List 1 & 2\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                mergeSort(&list1);
                printf("List 1 sorted:\n");
                display(list1);
                break;
                
            case 2:
                // Test case for loop detection
                printf("Testing List 1 for loop...\n");
                if (detectLoop(list1)) {
                    printf("Loop DETECTED in List 1.\n");
                } else {
                    printf("No loop detected in List 1.\n");
                }
                // Creating a loop for demonstration (e.g., last node points to the second node)
                if (list1 != NULL && list1->next != NULL) {
                    struct Node *temp = list1;
                    while(temp->next != NULL) temp = temp->next;
                    temp->next = list1->next;
                    printf("--- A temporary loop was created for testing. ---\n");
                    if (detectLoop(list1)) {
                        printf("Loop DETECTED after creation.\n");
                    }
                    // For safety, break the loop before further operations
                    temp->next = NULL;
                }
                break;
                
            case 3:
                // Ensure both lists are sorted before merging
                if (detectLoop(list1) || detectLoop(list2)) {
                    printf("Cannot merge. Please ensure lists are linear.\n");
                    break;
                }
                mergeSort(&list1);
                mergeSort(&list2);
                printf("Both lists sorted before merging.\n");

                struct Node *mergedList = sortedMerge(list1, list2);
                printf("Merged Sorted List:\n");
                display(mergedList);
                
                // Resetting for next run
                list1 = mergedList; 
                list2 = NULL;
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
