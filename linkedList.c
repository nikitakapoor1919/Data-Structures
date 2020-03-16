#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node * ptr;
};

typedef struct node NODE;
NODE *start=NULL;

void insBegin(int val)
{
 NODE *n;
 n=(NODE *)malloc(sizeof(NODE));
 n->data=val;
 if(start==NULL)
 {
   n->ptr=NULL;
   start=n;
 }
 else
 {
   n->ptr=start;
   start=n;
 }
 printf("%d INSERTED",val);
}
void delBegin()
{
  NODE *temp;
  
  if(start==NULL)
  printf("EMPTY LIST deletion not possible\n");
  else
  {
    temp=start;
    printf("%d DELETED",temp->data);
    start=temp->ptr;
    free(temp);
   
  }
  
}
void insEnd(int val)
{
NODE *temp;
NODE *n;
temp=start;
n=(NODE *)malloc(sizeof(NODE));
if(start==NULL)
 {
   n->data=val;
   n->ptr=NULL;
   start=n;
   printf("%d INSERTED",val);
   return;
 } 
else
 {
  while(temp->ptr!=NULL)
  {
  temp=temp->ptr; 
  }
 temp->ptr=n;
 n->data=val;
 n->ptr=NULL;
 printf("%d INSERTED",val);
 }
 
}
void delEnd()
{
NODE *temp;
NODE *u;
 if(start==NULL)
 printf("EMPTY LIST deletion not possible\n");
 else
 {
    temp=start;
     while(temp->ptr!=NULL)
     {
       u=temp; 
       temp=temp->ptr;
     }
    printf("%d DELETED",temp->data);
    free(temp);
    u->ptr=NULL;    

 }

}
void deleteALL()
{
NODE *temp;
temp=start;
while(temp->ptr!=NULL)
{
  temp=start;
  start=start->ptr;
  free(temp);
}
if(start==NULL)
printf("\n LINKED LIST DELETED\n");
}

void traverse()
{
  NODE *temp;
  temp=start;
  if(start==NULL)
  printf("\nLINKED LIST EMPTY\n");
  else
  {
  while(temp!=NULL)
  {
    printf(" %d ",temp->data);
    temp=temp->ptr;
  }
  }
  printf("\n");
}

void search(int val)
{
  NODE *temp;
  temp=start;
  int c=0;
  while(temp!=NULL)
  {
    if(temp->data==val)
    {
      c=1;
      printf("%d FOUND\n",val);
      break;
    }
    else
    temp=temp->ptr;
  }
  if(c==0)
  printf("%d NOT FOUND\n",val);
  
  
  printf("\n");
}

void insPOS(int a,int val)
{
int i;
NODE *temp;
NODE *n;
int count=0;
n=(NODE *)malloc(sizeof(NODE));
temp=start;
while(temp!=NULL)
{
	count++;
	temp=temp->ptr;
}
if(count==0||count==1)
insEnd(val);
if(count>=2)
{
  if(a>count||a<1)
  printf("Invalid position\n");

else
 {
  n->data=val;
  temp=start;
  for(i=1;i<a;i++)
  {
  	if(i==a-1)
  	{
  	  n->ptr=temp->ptr;
  	  temp->ptr=n;
	}
	temp=temp->ptr;
  }
 }
}
printf("%d INSERTED",val);
}
void delPOS(int a)
{
 int count=0;	
 int i;
 NODE *temp,*tp;
 if(start==NULL)
 printf("EMPTY LIST deletion not possible\n");
 else
 {
   temp=start;
   while(temp!=NULL)
   {
   	count++;
   	temp=temp->ptr;
   }
   if(a>count||a<1)
   printf("Invalid position\n");
   if(a==1)
   delBegin();
   else
   {
   temp=start;
   for(i=1;i<=a;i++)
   {
   	if(i==a-1)
   	{
   	 tp=temp->ptr;
	 temp->ptr=tp->ptr;
	 printf("%d DELETED \n",tp->data);
	 if(tp->ptr==NULL)
	 temp->ptr=NULL;
	 free(tp);	
	 break;
	}
	temp=temp->ptr;
	
   }
   }
 }
 
} 

int main()
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
   printf("5.Delete all\n");
   printf("6.Traverse\n");
   printf("7.Search\n");
   printf("8.Insert at specific pos\n");
   printf("9.Delete at specific pos\n");
   printf("10.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: 
              printf("Enter val to enter in linked list:");
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
      case 4:delEnd();
             printf("\n");
             break;
      case 5:deleteALL();
             printf("\n");
             break;
      case 6:printf("\nLinked List:\n"); 
             traverse();
             printf("\n");
             break;       
                               
      case 7:printf("Enter val to search in linked list:");
              scanf("%d",&x);
              search(x);
              printf("\n");
              break;
      case 8:printf("Enter pos where you want to enter node\n");
             scanf("%d",&a); 
             printf("Enter val to enter in linked list:");
             scanf("%d",&x);  
             insPOS(a,x);   
             break;
      case 9:printf("Enter pos where you want to delete node\n");
             scanf("%d",&a);   
             delPOS(a);      
    }
  }while(ch!=10);
  return 0;
}

