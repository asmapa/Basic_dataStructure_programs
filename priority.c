//priority queue opeartions

#include <stdio.h>

#define MAX_SIZE 100

// Structure for an element in the priority queue
struct PriorityQueueElement {
    int term;      // The value of the element
    int priority;  // Priority of the element
};

struct PriorityQueueElement p[MAX_SIZE]; // The array to store priority queue elements
int front = -1;  // Pointer to the front of the queue
int rear = -1;   // Pointer to the rear of the queue

// Function to check if the priority queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the priority queue is full
int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

// Function to insert an element with a priority into the priority queue
void insert(int term, int priority) {
    if (isFull()) {
        printf("Priority Queue is full. Cannot insert.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
        p[rear].term = term;
        p[rear].priority = priority;
    } else {
        int i = rear;

        while (i >= front && priority <= p[i].priority) {
            p[i + 1] = p[i];
            i--;
        }

        p[i + 1].term = term;
        p[i + 1].priority = priority;
        rear++;
    }
}

// Function to remove and return the element with the highest priority
int delete() {
    if (isEmpty()) {
        printf("Priority Queue is empty. Cannot delete.\n");
        return -1;
    }

    int highestPriorityTerm = p[front].term;

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }

    return highestPriorityTerm;
}

// Function to display the elements in the priority queue
void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue Elements: \n");
    for (int i = front; i <= rear; i++) {
        printf("term: %d, priority: %d\n", p[i].term, p[i].priority);
    }
}

int main() {
    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int term, priority;
        printf("Enter element %d and its priority: ", i + 1);
        scanf("%d %d", &term, &priority);
        insert(term, priority);
    }

    display();

    int highestPriorityTerm = delete();
    printf("Deleted element with term: %d\n", highestPriorityTerm);

    display();

    return 0;
}
