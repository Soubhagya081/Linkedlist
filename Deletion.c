#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head,*newnode,*temp;

void creation() // Creation of a linkedlist
{
    int choice=1;
    head=NULL;
    while(choice)
    {
        
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the Data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
        {
            head=temp=newnode;
        }

        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        printf("\nDo you want to continue(0/1)?");
        scanf("%d",&choice);
    }
}

void display() // For display the list
{
    int count=0;
    temp=head;
    printf("\nThe List is ");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
        count++;
    }
    if(head==NULL)
    printf("empty");
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
        printf("\n...................................\n1.For create the linkedlist\n2.For display the list\n3.For delete node from begining\n4.For delete node from End\n5.For delete node at specefic position\n6.For exit the programme\nEnter the choice : ");
        scanf("%d",&a);

        switch(a)
        {
            case 1:
            {
                creation();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                delatbeg();
                break;
            }
            case 4:
            {
                delatend();
                break; 
            }
            case 5:
            {
                delatspecefied();
                break;
            }
            case 6:
            {
                printf("\n....................Exit Point.....................");
                break;
            }
            default:
            {
                printf("Enter the option from(1/2/3/4/5/6)");
                break;
            }
        }
    }while(a!=6);
}