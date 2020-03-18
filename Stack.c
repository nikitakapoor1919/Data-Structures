#include<stdio.h>
# define MAX 10
int top=-1;
int stack[MAX]; 

int isFull()
{
 if(top==MAX-1)
 return 1;
 else
 return 0; 
}

int isEmpty()
{
 if(top==-1)
  return 1;
 else
 return 0;
 printf("\nUnderflow\n");
}

void push(int item)
{
 if(isFull())
 printf("\nOVERFLOW\n");
 else
 {
   top++;
   stack[top]=item;
   printf("%d PUSHED",item);
 }
}

void pop()
{
  if(isEmpty())
  printf("\nUNDERFLOW\n");
  else
  {
    printf(" %d POPPED\n",stack[top]);
    --top;
    
  }
}

void display()
{
  int i;
  if(isEmpty())
  printf("\nEMPTY STACK\n");
  else
  {
  printf("STACK :\n");
  for(i=0;i<=top;i++)
  {
    printf("%d ",stack[i]);
  }
  printf("\n TOP:%d",top);
  }
}  

void main()
{
  int ch;
  int x;
  do
  {
   printf("\nEnter choice...\n"); 
   printf("1.PUSH\n");
   printf("2.POP\n");
   printf("3.DISPLAY\n");
   printf("4.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: 
              printf("Enter val to enter Stack:");
              scanf("%d",&x);
              push(x);
              printf("\n");
              break;
      case 2:  pop();
              printf("\n");
              break;              
      case 3: display();
              printf("\n");
              break;     
           
    }
  }while(ch!=4);
}

