#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node_l
{
    int data;
    struct node_l *link;
} node ;

node  *create( node *head)
{ 
    
    int item;
    int ch=1,option;
    if(head!=NULL)
    {
        printf("------the list already exists----");
        return (head);
    }
        
          node* temp= ( node*)malloc(sizeof( node));
          temp=head;

          while (ch==1)
     { 
        
         printf("\nenter the element we want to enter in linkedlist : ");
         scanf("%d",&item);
          node* new= ( node*)malloc(sizeof( node));
          new->data=item;
          new->link=NULL;
        if (head==NULL)
        {
            temp=head=new;
        }
        else
        {
            temp->link=new;
            temp=new;
        }
           
        printf("\t\n element entered successfully \n\n");
       printf("  1)  continue\n ");
       printf(" 2)  discontinue   :");
       scanf("%d",&option);
       ch=option;
        }

     return (head);
}
node  *delend(node *head)
{
    node *temp,*temp1;
    
    for (temp=head;temp->link!=NULL;temp=temp->link)
    {
      temp1=temp;
    }
    temp1->link=NULL;
    temp=temp1;
    return (head);
}
node  *delfirst(node *head)
{    
    head=head->link;
    return (head);
}
node *delete(node *head)
{
    node *temp,*temp1;
    
    temp=head;
    
    if (head==NULL)
    {
        printf("\t\n---------list is empty----\n");
        return (head);
    } 
    
    for(temp=head;temp!=NULL;temp=temp->link)
    {
        for(temp=head;(temp!=NULL)&&((temp->data )>0);temp=temp->link)
           temp1=temp;
         if (temp==NULL)  
         {
             return (head);
         }
           
           if(temp==head)
        {
          head=delfirst(head);
        }
         else
    {
       temp1->link=temp1->link->link;
    }
    
    }
    free(temp);
    printf("\n\t----negative elements deleted succesfully-----\n");

    return (head);
}


void print( node *head)
{
    node *t;
   
    if (head==NULL)
    {
        printf("------linked list is empty or exists already----");
     return ;
    }
    else
    
    { 
        t=head;
        printf("\n\t   address    data    new address");
        while(t!=NULL)
        {   
            printf("\n\t %10u    %d   %10u",t,t->data,t->link);
            t=t->link;
        }
    }
    
}
int main()
{
    int choice;
    node* head= ( node*)malloc(sizeof( node));
     head=NULL;
     while (1)
     {
      printf("\n\t-----------main menu-------\n");
     printf("\t 1) create  SLL\n");
     printf("\t 2) delete all node with negative elements\n");
     printf("\t 3) display\n");
     printf("\t 4) delete at end\n");
     printf("\t 5) del first\n");
     printf("\t 6) exit\n");

     printf("\tenter the choice  ");

     scanf("%d",&choice);

        switch(choice)
      {
        case 1:
                  head=create(head);
             break;
        case 2:
               head=delete(head);
                  
                  break;
        case 3:
                  print(head);
                  break;
        case 4:
                 head=delend(head);
                   break;
        case 5:
        
                 head=delfirst(head);
                  break;
        case 6 :
            exit(0);

     }
     }
 }