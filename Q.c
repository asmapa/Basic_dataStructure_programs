//This is the code for basic queue operations in C

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int x)
{
    if (rear == MAX - 1)
    {
        printf("Queue overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = x;
        printf("Element: %d\n", queue[rear]);
    }
    else
    {
        rear = rear + 1;
        queue[rear] = x;
    }
}

void dlt()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front = front + 1;
    }
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, item;
    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                dlt();
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
