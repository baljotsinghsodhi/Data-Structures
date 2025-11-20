#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

void insert_at_end(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node with data %d inserted at end.\n", data);
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    if (temp->next == NULL) {
        printf("Deleted: %d\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL) temp = temp->next;
    printf("Deleted: %d\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

void reverse_display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) temp = temp->next;

    printf("List elements (Reverse): ");
    while (temp != NULL) {
        printf("%d <- ", temp->data);
        temp = temp->prev;
    }
    printf("START\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;
    do {
        printf("\n--- DLL Menu ---\n");
        printf("1. Insert at End\n2. Delete Last Node\n3. Display (Forward)\n4. Display (Reverse)\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 2:
                delete_at_end();
                break;
            case 3:
                display();
                break;
            case 4:
                reverse_display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}
