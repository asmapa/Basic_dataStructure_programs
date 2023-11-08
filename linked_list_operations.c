#include<stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void insert_at_front(struct node *header, int x) {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = x;
    new->link = header->link;
    header->link = new;
}

void display(struct node *header) {
    struct node *ptr = header->link;

    printf("THE ELEMENTS ARE:\n");

    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
}

void insert_at_end(struct node *header, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    struct node *ptr = header;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }

    ptr->link = new_node;
}

void insert_in_between(struct node *header, int data, int position) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;

    struct node *ptr = header;
    int count = 0;

    while (ptr != NULL && count < position - 1) {
        ptr = ptr->link;
        count++;
    }

    new_node->link = ptr->link;
    ptr->link = new_node;
}

void delete_at_front(struct node *header) {
    if (header->link != NULL) {
        struct node *temp = header->link;
        header->link = temp->link;
        free(temp);
    } else {
        printf("List is empty\n");
    }
}

void delete_at_end(struct node *header) {
    struct node *ptr = header;
    struct node *prev = NULL;

    if (header->link == NULL) {
        printf("List is empty\n");
        return;
    }

    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }

    prev->link = NULL;
    free(ptr);
}

void delete_any(struct node *header, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be 1 or greater.\n");
        return;
    }

    struct node *ptr = header->link;  // Start from the first node, not the header
    struct node *temp = header;
    int count = 1;  // Start from position 1

    while (ptr != NULL && count < position) {
        temp = ptr;
        ptr = ptr->link;
        count++;
    }

    if (ptr == NULL) {
        printf("Position %d is out of bounds. No node to delete.\n", position);
        return;
    }

    temp->link = ptr->link;
    free(ptr);
}

int main() {
    int n, num, x, position;
    struct node *header = (struct node*) malloc(sizeof(struct node));
    header->link = NULL;
    header->data = 0;
    struct node *ptr = header;

    printf("Enter the number of elements you need to add into the linked list:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct node *temp = (struct node*) malloc(sizeof(struct node));
        printf("Enter a number to insert: ");
        scanf("%d", &num);
        temp->data = num;
        temp->link = NULL;
        ptr->link = temp;
        ptr = ptr->link;
    }

    ptr = header->link;

    printf("THE ELEMENTS ARE:\n");

    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }

    printf("\nEnter choice to perform other operations:\n");
    printf("1. Insert at front\n");
    printf("2. Insert at end\n");
    printf("3. Insert in between\n");
    printf("4. Delete at front\n");
    printf("5. Delete at end\n");
    printf("6. Delete from between\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter an element to insert at the front: ");
                scanf("%d", &x);
                insert_at_front(header, x);
                break;
            case 2:
                display(header);
                break;
            case 3:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &x);
                insert_at_end(header, x);
                break;
            case 4:
                delete_at_front(header);
                break;
            case 5:
                delete_at_end(header);
                break;
            case 6:
                printf("Enter the position to delete (1-based): ");
                scanf("%d", &position);
                delete_any(header, position);
                break;
        }
    }
}

   
