#include<stdio.h>
# define MAX 10
int top1=-1;
int top2=MAX;
int stack[MAX]; 

int isFull()
{
 if(top1==MAX-1)
 return 1;
 if(top2==0)
 return 1;
 if(top1==top2-1||top2==top1+1)
 return 1;
 else
 return 0; 
}

int isEmpty1()
{
  if(top1==-1)
  return 1;
  else
  return 0;
}


int isEmpty2()
{
  if(top2==MAX)
  return 1;
  else
  return 0;
}
void push1(int item)
{
 if(isFull())
 printf("\nOVERFLOW\n");
 else
 {
   top1++;
   stack[top1]=item;
   printf("%d PUSHED",item);
 }
}

void pop1()
{
  if(isEmpty1())
  printf("\nUNDERFLOW\n");
  else
  {
    printf(" %d POPPED\n",stack[top1]);
    --top1;
    
  }
}

void display1()
{
	int i;
  if(isEmpty1())
  printf("\nEMPTY STACK\n");
  else
  {
  printf("STACK :\n");
  for( i=0;i<=top1;i++)
  {
    printf("%d ",stack[i]);
  }
  printf("\nTOP:%d",top1);
  }
}  

void push2(int item)
{
  if(isFull())
  printf("\nOVERFLOW\n");
  else
  {
    --top2;
    stack[top2]=item;
    printf("%d PUSHED",item);
  }
}


void pop2()
{
  if(isEmpty2())
  printf("\nUNDERFLOW\n");
  else
  {
    printf(" %d POPPED\n",stack[top2]);
    top2++;
  }
}
void display2()
{
	int i;
   if(isEmpty2())
  printf("\nEMPTY STACK\n");
  else
  {
  printf("STACK :\n");
  for(i=MAX-1;i>=top2;i--)
  {
    printf("%d ",stack[i]);
  }
   printf("\nTOP:%d",top2);
  }
}  
void main()
{
int ch;
  int a,x;
  do
  {
   printf("\nEnter choice...\n"); 
   printf("1.PUSH IN STACK 1\n");
   printf("2.POP IN STACK 1\n");
   printf("3.DISPLAY  STACK 1\n");
   printf("4.PUSH IN STACK 2\n");
   printf("5.POP IN STACK 2\n");
   printf("6.DISPLAY  STACK 2\n");
   printf("7.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter val to enter Stack:");
              scanf("%d",&x);
              push1(x);
              printf("\n");
              break;
      case 2: pop1();
              printf("\n");
              break;              
      case 3: display1();
              printf("\n");
              break;     
      case 4: printf("Enter val to enter Stack:");
              scanf("%d",&x);
              push2(x);
              printf("\n");
              break;
      case 5: pop2();
              printf("\n");
              break;              
      case 6: display2();
              printf("\n");
              break;              
    }
  }while(ch!=7);
}

