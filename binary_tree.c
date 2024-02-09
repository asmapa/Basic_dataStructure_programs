#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;
}

void binary_tree(struct node *ptr,int data)
{
    if(ptr!=NULL)
    {
        ptr->data=data;

        printf("is it have left child(Y or N)???");
        char c;
        scanf(" %c",&c);
        if(c=='Y')
        {
            struct node *lc=createNode(-1);
            ptr->left=lc;
            printf("enter data for insert:");
            int n;
            scanf("%d",&n);
            binary_tree(lc,n);
        }
        else
        {
            ptr->left=NULL;
        }


        printf("is it have right child(Y or N)??");
        char t;
        scanf(" %c",&t);
        if(t=='Y')
        {
            struct node *rc=createNode(-1);
            ptr->right=rc;
            printf("enter data:");
            int b;
            scanf("%d",&b);
            binary_tree(rc,b);
        }
        else
        {
            ptr->right=NULL;
        }
    }
}

void inorder(struct node *root)
{
           if (root == NULL) {
        return; // Base case: exit the function if root is NULL
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);

    
}
int main()
{
    struct node *root=createNode(-1);
    printf("enter first element for insert:");
    int num;
    scanf("%d",&num);
    binary_tree(root,num);

    inorder(root);

}
