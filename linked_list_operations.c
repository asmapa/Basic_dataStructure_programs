/* This contains operations like 
1.insert at front
2.insert at end
3.insert at any position
4.delete from front
5.delete from end
6.delete from midddle
7.sort
8.reverse
9.display*/


#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *createNode(int key)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=key;
    new_node->next=NULL;
}

struct node *IF(struct node *head,int data)
{
    struct node *no=createNode(data);

    if(head == NULL)
    {
        head=no;
    }
    else
    {
        no->next=head;
        head=no;

    }
    return head;
}

struct node *IB(struct node *head,int data)
{
    struct node *no=createNode(data);
    if(head==NULL)
    {
        head=no;
    }
    else
    {
        struct node *current=head;
        while(current->next !=NULL)
        {
            current=current->next;
        }
        current->next=no;
    }
    return head;
}

struct node *IM(struct node *head,int key,int data)
{
    struct node *no=createNode(data);
    if(head==NULL)
    {
        head=no;
    }
    else
    {
        struct node *current=head;
        while(current->next != NULL && current->data !=key)
        {
            current=current->next;
        }
        no->next=current->next;
        current->next=no;
    }
    return head;
}

struct node *DF(struct node *head)
{
    if(head==NULL)
    {
        printf("it is empty");
    }
    struct node *current=head;
    head=current->next;
    free(current);
    return head;

    
}

struct node *DE(struct node *head)
{
    struct node *current=head;
    struct node *prev=NULL;
    while(current->next !=NULL)
    {
        prev=current;
        current=current->next;
    }
    prev->next=NULL;
    free(current);

    return head;
}

struct node *DM(struct node *head,int key)
{
    struct node *current=head;
    struct node *prev=NULL;
    while(current !=NULL && current->data !=key)
    {
        prev=current;
        current=current->next;
    }
    prev->next=current->next;
    free(current);

    return head;
}

struct node *reverse(struct node *head)
{
    struct node *next=NULL;
    struct node *prev=NULL;
    struct node *current=head;

    while(current !=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

struct node *sort(struct node *head)
{
    struct node *current=head;
    while(current !=NULL)
    {
        struct node *min=current;
        struct node *temp=current->next;
        while(temp != NULL)
        {
            if(temp->data < min->data)
            {
                min=temp;
            }
            temp=temp->next;
        }

        int t=current->data;
        current->data=min->data;
        min->data=t;

        current=current->next;
    }

      return head;  
}

void display(struct node *head)
{
    struct node *current=head;
    while(current !=NULL)
    {
        printf("%d",current->data);
        printf("\t");
        current=current->next;
    }
}

int main()
{
    struct node *head;
 
        
    while(1){
     printf("enter a choice:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("enter data:");
        int data;
        scanf("%d",&data);
        head=IF(head,data);
        break;

        case 2:printf("enter:");
        int da;
        scanf("%d",&da);
        head=IB(head,da);
        break;

        case 3:printf("Enter a number after that you can insert new node:");
        int dat;
        scanf("%d",&dat);
        printf("enter data for insert:");
        int d;
        scanf("%d",&d);
        head=IM(head,dat,d);
        break;

        case 4:head=DF(head);
        break;

        case 5:head=DE(head);
        break;

        case 6:printf("enter the data you want to delete:");
        int g;
        scanf("%d",&g);
        head=DM(head,g);
        break;

        case 7:head=reverse(head);
        break;

        case 8:head=sort(head);
        break;

        case 9:display(head);
        break;
    }
    }
}
