//This is code for circular queue operations in C language

#include <stdio.h>
#define MAX 5

int circularQueue[MAX];
int front = -1;
int rear = -1;



// Function to insert an element into the circular queue
void enqueue(int x)
{
    if ((front == 0 && rear == MAX - 1) || (front != 0 && rear == front - 1))
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
        circularQueue[rear] = x;
        printf("Element %d enqueued.\n", x);
    }
}

// Function to dequeue an element from the circular queue
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        int removed = circularQueue[front];
        printf("Element %d dequeued.\n", removed);

        if (front == rear)
        {
            front = rear = -1; // Reset when the last element is removed
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
        }
    }
}

// Function to display the elements in the circular queue
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Circular Queue elements: ");
        int i = front;
        do
        {
            printf("%d ", circularQueue[i]);
            if (i == MAX - 1)
            {
                i = 0;
            }
            else
            {
                i = i + 1;
            }
        } while (i != rear);
        printf("%d\n", circularQueue[rear]);
    }
}

int main()
{
    int choice, item;
    do
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
