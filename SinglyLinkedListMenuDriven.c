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

void create()
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
}
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
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void delatbeg()  // For delete node from begining
{
    temp=head;
    head=head->next;
    free(temp);
}

void delatend()  //For delete node from end
{
    temp=head;
    struct node * prevnode;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    head=NULL;
    else
    {
        prevnode->next=NULL;
    }
    free(temp);
}

void delatspecefied()
{
    temp=head;
    int count=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    temp=head;
    int pos,i=1;
    printf("\nEnter the position you want to delete ");
    scanf("%d",&pos);
    
    
    if(pos==1) // for deleting at 1st position
    {
        struct node * firstnode;
        firstnode=head;
        head=head->next;
        free(firstnode);
    }
    
    else if(pos<2||pos>count)
    printf("\nInvalid Position");
    
    else
    {
        struct node * nextnode;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
    }
}


void main()
{
    
    int a;
    
    do{
    printf("\n....................\nChoose an option\n0.For creation\n1. For Inserting at Begining\n2. For Inserting at End\n3. For Inserting at Specefied Position\n4. For Display\n5.For deletion at begining\n6.For deletion at end\n7.For deletion at specefic position\n8. For Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&a);
        switch(a)
        {
            case 0:
            {
                create();
                break;
            }
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
                delatbeg();
                break;
            }
            case 6:
            {
                delatend();
                break;
            }
            case 7:
            {
                delatspecefied();
                break;
            }
            case 8:
            {
            printf("\nExit point............");
            break;
            }
            default:
            {
                printf("Please enter a valid choice 1/2/3/4/5/6/7/8");
            }
        }   
    }while(a!=8);
}
