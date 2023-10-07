#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;
struct node *newnode;
struct node *temp;
int count;

void display()
{
    count=0;
    temp=head;
    printf("\nThe Linkedlist Values are : ");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
}

void insertbeg()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}

void insertend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data ");
    scanf("%d",&newnode->data);
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode->next=NULL;
    temp->next=newnode;
}

void insspec()
{
    int pos,i=1;
    printf("\nEnter the position after you want to add the node : ");
    scanf("%d",&pos);
    if(pos<1||pos>count)
    printf("\nInvalid position !!");
    else
    {
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data ");
        scanf("%d",&newnode->data);
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}


void main()
{
    head=NULL;
    int choice=1;
    while(choice)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if (head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    printf("Do you want to continue(0/1)");
    scanf("%d",&choice);
    }
    
    display();
    int a;
    
    do{
    printf("\n....................\nChoose an option\n1. For Inserting at Begining\n2. For Inserting at End\n3. For Inserting at Specefied Position\n4. For Display\n5. For Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&a);
        switch(a)
        {
            case 1:
            {
            insertbeg();
            break;
            }
            
            case 2:
            {
            insertend();
            break;
            }
            case 3:
            {
            insspec();
            break;
            }
            case 4:
            {
            display();
            break;
            }
            case 5:
            {
            printf("\nExit point............");
            break;
            }
            default:
            {
                printf("Please enter a valid choice 1/2/3/4/5");
            }
        }   
    }while(a!=5);
}