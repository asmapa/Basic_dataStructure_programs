#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *end=NULL;

struct node *createNode(int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

struct node *insert(struct node *head,int data)
{
    struct node *nod=createNode(data);
    if(head==NULL)
    {
        head=nod;
        start=nod;
        end=nod;
        end->next=start;
    }
    else
    {
        nod->next=head;
        head=nod;
        start=nod;
        end->next=start;
    }
    return head;
}

struct node *IE(struct node *head,int data)
{
    struct node *nod=createNode(data);
    if(head==NULL)
    {
        head=nod;
        start=nod;
        end=nod;
        end->next=start;
    }
    else
    {
        end->next=nod;
        nod->next=start;
        end=nod;
    }

    return head;
}

struct node *DF(struct node *head)
{
    if(head==NULL)
    {
        printf("it is empty");
    }
    else
    {
        struct node *temp=head;
        head=temp->next;
        start=temp->next;
        end->next=start;
        free(temp);
    }
    return head;
}

struct node *DB(struct node *head)
{
    if(head==NULL)
    {
        printf("it is empty");
    }
    else
    {
        struct node *temp=head;
        struct node *t=NULL;
        while(temp->next !=start)
        {
            t=temp;
            temp=temp->next;
        }
        end=t;
        end->next=start;
        free(temp);
    }
    return head;
}

void display(struct node *head)
{
    struct node *current=head;
    while(current->next != start)
    {
        printf("%d",current->data);
        printf("\t");
        current=current->next;
    }
    printf("%d",current->data);
    printf("\t");
}

int main()
{
    struct node *head=NULL;
    while(1)
    {
        printf("Enter your choice:");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter data:");
            int num;
            scanf("%d",&num);
            head=insert(head,num);
            break;

            case 2:printf("enter data:");
            int nu;
            scanf("%d",&nu);
            head=IE(head,nu);
            break;

            case 3:head=DF(head);
            break;

            case 4:head=DB(head);
            break;

            case 5:display(head);
            break;
        }
    }
}