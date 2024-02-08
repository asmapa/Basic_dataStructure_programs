#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int expo;
    struct node *next;
};

struct node *createNode(int coeff,int expo)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->coeff=coeff;
    new_node->expo=expo;
    new_node->next=NULL;

    return new_node;
}

struct node *insert(struct node *head,int coeff,int expo)
{
    struct node *no=createNode(coeff,expo);
    if(head==NULL)
    {
        head=no;
    }
    else
    {
        struct node *current=head;
        while(current->next != NULL)
        {
            current=current->next;
        }
        current->next=no;
    }

    return head;
}

struct node *add(struct node *p, struct node *q, struct node *r) {
    while (p != NULL && q != NULL) {
        if (p->expo == q->expo) {
            r = insert(r, p->coeff + q->coeff, p->expo);
            p = p->next;
            q = q->next;
        } else if (p->expo > q->expo) {
            r = insert(r, p->coeff, p->expo);
            p = p->next;
        } else {
            r = insert(r, q->coeff, q->expo);
            q = q->next;
        }
    }
    // Add remaining terms of p or q if any
    while (p != NULL) {
        r = insert(r, p->coeff, p->expo);
        p = p->next;
    }
    while (q != NULL) {
        r = insert(r, q->coeff, q->expo);
        q = q->next;
    }
    return r;
}

void display(struct node *head)
{
    struct node *current=head;
    while(current->next !=NULL){
        printf("%d x ^%d +",current->coeff,current->expo);
        current=current->next;
    }
    printf("%d x ^%d ",current->coeff,current->expo);
}


int main()
{
    struct node *p=NULL;
    struct node *q=NULL;
    struct node *r=NULL;

    printf("enter number of elemets for insert in 1st poly:");
    int num;
    scanf("%d",&num);

    for(int i=1;i<=num;i++)
    {
         printf("enter coeff %d:",i);
         int nu;
         scanf("%d",&nu);
         printf("enter expo %d",i);
         int e;
         scanf("%d",&e);
        p=insert(p,nu,e);
    }

    display(p);

     printf("enter number of elemets for insert in 2nd poly:");
    int a;
    scanf("%d",&a);

    for(int j=1;j<=a;j++)
    {
         printf("enter coeff %d:",j);
         int b;
         scanf("%d",&b);
         printf("enter expo %d",b);
         int c;
         scanf("%d",&c);
        q=insert(q,b,c);
    }

    display(q);

    r=add(p,q,r);
    printf("the result poly:");
    display(r);
}