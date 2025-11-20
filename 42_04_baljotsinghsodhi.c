#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
#define SIZE_Q1 5

int arr[MAX_SIZE];
// Queue 1 (front to SIZE_Q1-1)
int front1 = -1, rear1 = -1;
// Queue 2 (SIZE_Q1 to MAX_SIZE-1)
int front2 = -1, rear2 = SIZE_Q1 - 1;

void enqueue1() {
    int item;
    if (rear1 == SIZE_Q1 - 1) {
        printf("Queue 1 Overflow\n");
    } else {
        printf("Enter item for Queue 1: ");
        scanf("%d", &item);
        if (front1 == -1) front1 = 0;
        rear1++;
        arr[rear1] = item;
        printf("Enqueued %d to Queue 1\n", item);
    }
}

void dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        printf("Queue 1 Underflow\n");
        front1 = -1; rear1 = -1;
    } else {
        printf("Dequeued %d from Queue 1\n", arr[front1]);
        front1++;
        if (front1 > rear1) {
            front1 = -1; rear1 = -1;
        }
    }
}

void enqueue2() {
    int item;
    if (rear2 == MAX_SIZE - 1) {
        printf("Queue 2 Overflow\n");
    } else {
        printf("Enter item for Queue 2: ");
        scanf("%d", &item);
        if (front2 == SIZE_Q1 - 1) front2 = SIZE_Q1;
        rear2++;
        arr[rear2] = item;
        printf("Enqueued %d to Queue 2\n", item);
    }
}

void dequeue2() {
    if (front2 == SIZE_Q1 - 1 || front2 > rear2) {
        printf("Queue 2 Underflow\n");
        front2 = SIZE_Q1 - 1; rear2 = SIZE_Q1 - 1;
    } else {
        printf("Dequeued %d from Queue 2\n", arr[front2]);
        front2++;
        if (front2 > rear2) {
            front2 = SIZE_Q1 - 1; rear2 = SIZE_Q1 - 1;
        }
    }
}

void display1() {
    if (front1 == -1) {
        printf("Queue 1 is empty\n");
    } else {
        printf("Queue 1 elements: ");
        for (int i = front1; i <= rear1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void display2() {
    if (front2 == SIZE_Q1 - 1) {
        printf("Queue 2 is empty\n");
    } else {
        printf("Queue 2 elements: ");
        for (int i = front2; i <= rear2; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Two Queues Menu ---\n");
        printf("1. Enqueue to Queue 1\n2. Dequeue from Queue 1\n3. Display Queue 1\n");
        printf("4. Enqueue to Queue 2\n5. Dequeue from Queue 2\n6. Display Queue 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue1();
                break;
            case 2:
                dequeue1();
                break;
            case 3:
                display1();
                break;
            case 4:
                enqueue2();
                break;
            case 5:
                dequeue2();
                break;
            case 6:
                display2();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
    return 0;
}
