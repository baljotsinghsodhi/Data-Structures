#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void create_node() {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node with data %d created.\n", data);
}

void insert_at_end(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void delete_at_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    printf("Deleted: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void reverse() {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("List reversed.\n");
}

void find_middle() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element is: %d\n", slow->data);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;
    do {
        printf("\n--- SLL Menu ---\n");
        printf("1. Create/Insert Node\n2. Delete Last Node\n3. Reverse List\n4. Find Middle\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_node();
                break;
            case 2:
                delete_at_end();
                break;
            case 3:
                reverse();
                break;
            case 4:
                find_middle();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
