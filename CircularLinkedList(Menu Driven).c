#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node *tail,*newnode,*temp;

void createCLL()
{
    int choice=1;
    tail=NULL;
    while(choice)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(tail==NULL)
    {
        tail=newnode;
        tail->next=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    printf("\nDo you want to continue(1/0)?");
    scanf("%d",&choice);
    }
}

void display()
{
    temp=tail;
    if(temp==NULL)
    {
        printf("\nList is empty .");
    }
    else
    {
        printf("\nThe list is ");
        while(temp->next!=tail)
        {
            printf("%d ",temp->next->data);
            temp=temp->next;
        }
        printf("%d",temp->next->data);
    }
    
}

void createNewNode()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
}

void insertAtBeg()
{
    createNewNode();
    newnode->next=tail->next;
    tail->next=newnode;
}

void insertAtEnd()
{
    createNewNode();
    newnode->next=tail->next;
    tail->next=newnode;
    tail=newnode;
}

int lengthOfList()
{
    int len = 0;
    temp=tail->next;
    while(temp!=tail)
    {
        len++;
        temp=temp->next;
    }
    len++;
    return len;
}

void insertAtSpeceficPos()
{
    int l = lengthOfList();
    int pos;
    printf("\nEnter the position you want to insert the node");
    scanf("%d",&pos);
    int i=1;
    
    if(pos<=0||pos>l+1)
    printf("\nInvalid Position !!");
    
    else if(pos==1)
    insertAtBeg();
    
    else if(pos==l+1)
    insertAtEnd();
    
    else
    {
        createNewNode();
        temp=tail->next;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void delAtBeg()
{
    temp=tail->next;
    if(tail==NULL)
        printf("\nThe list is empty");
    else if(temp->next==temp)
    {
        tail=NULL;
        free(temp);
    }
    else
    {
        tail->next=temp->next;
        free(temp);
    }
}

void delAtEnd()
{
    temp=tail->next;
    if(tail==NULL)
        printf("\nThe list is empty");
    else if(temp->next==temp)
    {
        tail=NULL;
        free(temp);
    }
    else
    {
        struct node * extra;
        temp=tail;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        extra=temp->next;
        temp->next=tail->next;
        tail=temp;
        free(extra);
    }
}

void delAtSpeceficPos()
{
    int pos;
    int i=1;
    printf("\nEnter the position you want to delete : ");
    scanf("%d",&pos);
    int l = lengthOfList();
    if(pos<=0||pos>l)
    printf("\nInvalid Position!!");
    else if(pos==1)
    delAtBeg();
    else if(pos==l)
    delAtEnd();
    else
    {
        temp=tail->next;
        struct node * extra;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        extra=temp->next;
        temp->next=extra->next;
        free(extra);
    }
}
int main()
{
    int val;
    do{
        printf("\n................\n1.For creating the List\n2.For display\n3.For inserting at begining\n4.For insert at end\n5.Insert at specefic position\n6.For delete at begining\n7.For delete at end\n8.For delete at specefic position\n9.For exit\n................\nEnter your choice : ");
        scanf("%d",&val);
        switch(val)
        {
            case 1:
            {
                createCLL();
                break;
            }
            case 2:
            {
                display();
                break;
            }
            case 3:
            {
                insertAtBeg();
                break;
            }
            case 4:
            {
                insertAtEnd();
                break;
            }
            case 5:
            {
                insertAtSpeceficPos();
                break;
            }
            case 6:
            {
                delAtBeg();
                break;
            }
            case 7:
            {
                delAtEnd();
                break;
            }
            case 8:
            {
                delAtSpeceficPos();
                break;
            }
            case 9:
            {
                printf("\nEXIT POINT");
                break;
            }
            default :
            {
                printf("\nYou choose wrong option!!");
                break;
            }
        }
    }while(val!=9);
    return 0;
}