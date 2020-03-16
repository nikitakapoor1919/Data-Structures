
#include<stdio.h>
#include<stdlib.h>

struct node
{
int coe;
int exp;
struct node * next;
};

typedef struct node NODE;

void create_poly(NODE **start)
{
int flag;
int c,e;
NODE *node;
node=(NODE *)malloc(sizeof(NODE));
*start=node;
do{
  printf("Enter coeffcient\n");
  scanf("%d",&c);
  printf("Enter exponent\n");
  scanf("%d",&e);
  node->coe=c;
  node->exp=e;
  node->next=NULL;
  printf("\nWant to add more??\n");
  scanf("%d",&flag);
  if(flag)
  {
   NODE *newnode=(NODE*)malloc(sizeof(NODE));
   node->next=newnode;
   node=newnode;
   node->next=NULL;
  
  }
  }while(flag);
 
}
void print_poly(NODE *node)
{
  printf("POLYNOMINAL:\n");
  while(node!=NULL)
  {
    printf(" %d^%d",node->coe,node->exp);
    node=node->next;
    if(node!=NULL)
    printf("+");
  }
  printf("\n");
}
void add_poly(NODE *p,NODE *q,NODE **temp3)
{
 NODE *temp1,*temp2 ,*node;
 temp1=p;
 temp2=q;
 node=(NODE *)malloc(sizeof(NODE));
 node->next=NULL;
 *temp3=node;
 while(temp1 && temp2)
 {
   if(temp1->exp==temp2->exp)
    {
     node->coe=temp1->coe+temp2->coe;
     node->exp=temp1->exp;
   
     temp1=temp1->next;
     temp2=temp2->next;
     }
    else if(temp1->exp<temp2->exp)
     {
     node->coe=temp1->coe;
     node->exp=temp1->exp;
    
     temp1=temp1->next;
     
     }
     else if(temp1->exp>temp2->exp)
     {
     node->coe=temp2->coe;
     node->exp=temp2->exp;
   
     temp2=temp2->next;
     }
     if(temp1 && temp2)
     {
      NODE *newnode=(NODE*)malloc(sizeof(NODE));
      node->next=newnode;
      node=newnode;
      node->next=NULL;
     }
     
   
 }
 while(temp1||temp2)
 {
   NODE *newnode=(NODE*)malloc(sizeof(NODE));
   node->next=newnode;
   node=newnode;
   node->next=NULL;
   if(temp1)
   {
    node->exp=temp1->exp;
    node->coe=temp1->coe;
    temp1=temp1->next;
   }
    if(temp2)
   {
    node->exp=temp2->exp;
    node->coe=temp2->coe;
    temp2=temp2->next;
   }
 }
 
 
}
void main()
{

  int ch;
  int x;
  NODE *p,*q,*temp3;
  do
  {
   printf("\nEnter choice...\n"); 
   printf("1.Create first polynominal: \n");
   printf("2.Print first Polynominal:\n");
   printf("3.Create second polynominal: \n");
   printf("4.Print second Polynominal:\n");
   printf("5.Add Polynominal:\n");
   printf("6.Exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:create_poly(&p);
            break;
     case 2:print_poly(p);
            break;
     case 3:create_poly(&q);
            break;
     case 4:print_poly(q);
            break; 
     case 5:add_poly(p,q,&temp3);
            print_poly(temp3); 
            break;                     
   }
  }while(ch!=6);
}  

