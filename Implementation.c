#include<stdio.h>
#include<stdlib.h>
void main()
{
    struct node{
      int data;
      struct node *next;
    };
    
    struct node *head,*newnode,*temp;
    head = NULL;
    int choice =1;
    while (choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data : ");
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
        printf("Do you want to continue(Press 0/1)?");
        scanf("%d",&choice);
    }
    temp=head;
    int count=1;
    while(temp!=NULL)
    {
        printf("\nAt position %d data is %d",count,temp->data);
        temp=temp->next;
        count++;
    }
}