#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node * next;
struct node *prev;
};

typedef struct node NODE;
NODE *head=NULL;
NODE *tail=NULL;

void insBegin(int val)
{
 NODE *n;
 n=(NODE *)malloc(sizeof(NODE));
 n->data=val;
 if(head==NULL)
 {
   n->prev=NULL;
   n->next=NULL;
   tail=n;
   head=n;
 }
 else
 {
   n->prev=NULL;
   n->next=head;
   head=n;
   n->next->prev=n;
 }
 printf("%d INSERTED",val);
}
void delBegin()
{
  NODE *temp;
  
  if(head==NULL)
  printf("EMPTY LIST deletion not possible\n");
  else
  {
    temp=head;
    printf("%d DELETED",temp->data);
    head=temp->next;
    free(temp);
   
  }
  
}
void insEnd(int val)
{
NODE *n;
n=(NODE *)malloc(sizeof(NODE));
 n->data=val;
if(head==NULL)
 {
   n->next=NULL;
   n->prev=NULL;
   head=n;
   tail=n;
   printf("%d INSERTED",val);
   return;
 } 
else
 {
 tail->next=n;
 n->next=NULL;
 n->prev=tail;
 tail=n;
 printf("%d INSERTED",val);
 }
 
}
void delEnd()
{
 NODE * temp;
 if(tail==NULL)
 printf("EMPTY LIST deletion not possible\n");
 else if(tail->prev==NULL)
 {
     printf("%d DELETED",tail->data);
     tail=tail->next;
     free(tail);
 }
 else
 {
    temp=tail;
    tail=temp->prev;
    printf("%d DELETED",temp->data);
    free(temp);
    tail->next=NULL;
 }
}

void traverse()
{
  NODE *temp;
  temp=head;
  if(head==NULL)
  printf("\nLINKED LIST EMPTY\n");
  else
  {
  while(temp!=NULL)
  {
    printf(" %d ",temp->data);
    temp=temp->next;
  }
  }
  printf("\n");
}


void main()
{

  int ch;
  int a,x;
  do
  {
   printf("\nEnter choice...\n"); 
   printf("1.Insert at begin\n");
   printf("2.Insert at end\n");
   printf("3.Delete at begin\n");
   printf("4.Delete at end\n");
   printf("5.Traverse\n");
   printf("6.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter val to enter in linked list:");
              scanf("%d",&x);
              insBegin(x);
              printf("\n");
              break;
     case 2:  printf("Enter val to enter in linked list:");
              scanf("%d",&x);
              insEnd(x);
              printf("\n");
              break;              
      case 3: delBegin();
              printf("\n");
              break;     
      case 4: delEnd();
              printf("\n");
              break;
      case 5: printf("\nLinked List:\n"); 
              traverse();
              printf("\n");
              break;       
   
      
    }
  }while(ch!=6);
}

