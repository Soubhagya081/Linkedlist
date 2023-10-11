  #include<stdio.h>
  #include<stdlib.h>
  
  struct node
  {
    int data;
    struct node * next;
    struct node * prev;
  };
  
  struct node *head,*tail;
  struct node *newnode;
  struct node *temp;
  
  void newnodecreation()
  {
      newnode = (struct node*)malloc(sizeof(struct node));
      printf("\nEnter the Data : ");
      scanf("%d",&newnode->data);
      newnode->next=NULL;
      newnode->prev=NULL;
  }
  
  void createlist()
  {
      int choice=1;
      head=NULL;
      while(choice)
      {
          newnodecreation();
          if(head==NULL)
          {
              head=tail=newnode;
          }
          else
          {
              tail->next=newnode;
              newnode->prev=tail;
              tail=tail->next;
          }
          printf("\nDo you want to continue(0/1)?");
          scanf("%d",&choice);
      }
  }
  
  void insertatbeg()
  {
      newnodecreation();
      if(head==NULL)
      {
          head=tail=newnode;
      }
      else
      {
          newnode->next=head;
          head->prev=newnode;
          head=newnode;
      }
  }
  
  void insertatend()
  {
      newnodecreation();
      newnode->prev=tail;
      tail->next=newnode;
      tail=newnode;
  }
  
  int lengthoflist()
  {
      int len=0;
      temp=head;
      while(temp!=NULL)
      {
          len++;
          temp=temp->next;
      }
      return len;
  }
  
  void insertatspecificpos()
  {
      
      
      int i=1,pos;
      printf("\nEnter the position you want to add the node ");
      scanf("%d",&pos);
      int l =lengthoflist();
      
      if(pos<=0||pos>l+1)
        printf("\nInvalid Position");
        
        
        else if(pos==1)
            insertatbeg();
        else if(pos==l+1)
            insertatend();
        else
        {
            temp=head;
            newnodecreation();
            while(i<pos-1)
            {
               temp=temp->next;
               i++;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            newnode->next->prev=newnode;
            temp->next=newnode;
        }
      
  }
  
  void display()
  {
      temp=head;
      printf("\nThe list is ");
      if(temp==NULL)
      printf("empty");
      while(temp!=NULL)
      {
          printf("%d\t",temp->data);
          temp=temp->next;
      }
  }
  
  
  int main()
  {
      int val;
      do
      {
          printf("\n...........................\nThe choices are\n1.Create list\n2.Insert node at beginng\n3.Insert node at end\n4.Insert node at specefic position\n5.Display the list\n6.Exit from the list");
          printf("\nEnter your choice : ");
          scanf("%d",&val);
          switch(val)
          {
              case 1:
              {
                  createlist();
                  break;
              }
              case 2:
              {
                  insertatbeg();
                  break;
              }
              case 3:
              {
                  insertatend();
                  break;
              }
              case 4:
              {
                 insertatspecificpos();
                 break;
              }
              case 5:
              {
                  display();
                  break;
              }
              case 6:
              {
                  printf("\n........Exit point........");
                  break;
              }
              default:
              {
                  printf("\nChosse valid option(1/2/3/4/5/6");
                  break;
              }
          }
      }while(val!=6);
      return 0;
  }