//This is code for double ended queue operations

#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

// Function to check if the deque is empty
int isEmpty() {
    return (front == -1 && rear == -1);
}

// Function to check if the deque is full
int isFull() {
    return (front == 0 && rear == MAX - 1) || (rear == front - 1);
}

// Function to insert an element at the front of the deque
void insertFront(int x) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at the front.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1;
        } else {
            front = front - 1;
        }
        deque[front] = x;
        printf("Element %d inserted at the front.\n", x);
    }
}

// Function to insert an element at the rear of the deque
void insertRear(int x) {
    if (isFull()) {
        printf("Deque is full. Cannot insert at the rear.\n");
    } else {
        if (front == -1) {
            front = rear = 0;
        } else if (rear == MAX - 1) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        deque[rear] = x;
        printf("Element %d inserted at the rear.\n", x);
    }
}

// Function to remove an element from the front of the deque
void removeFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot remove from the front.\n");
    } else {
        int removed = deque[front];
        printf("Element %d removed from the front.\n", removed);
        if (front == rear) {
            front = rear = -1;
        } else if (front == MAX - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
    }
}

// Function to remove an element from the rear of the deque
void removeRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot remove from the rear.\n");
    } else {
        int removed = deque[rear];
        printf("Element %d removed from the rear.\n", removed);
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1;
        } else {
            rear = rear - 1;
        }
    }
}

// Function to display the elements in the deque
void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        do {
            printf("%d ", deque[i]);
            if (i == MAX - 1) {
                i = 0;
            } else {
                i = i + 1;
            }
        } while (i != rear);
        printf("%d\n", deque[rear]);
    }
}

int main() {
    int choice, item;
    do {
        printf("\n1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Remove from Front\n");
        printf("4. Remove from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the front: ");
                scanf("%d", &item);
                insertFront(item);
                break;

            case 2:
                printf("Enter the element to insert at the rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;

            case 3:
                removeFront();
                break;

            case 4:
                removeRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
