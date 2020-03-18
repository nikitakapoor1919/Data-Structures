#include<stdio.h>
# define MAX 5
int front=-1,rear=-1;
int q[MAX];

int isfull()
{
  if(rear==MAX-1)
  return 1;
  else
  return 0;
}

int isempty()
{
  if(front==-1)
  return 1;
  else
  return 0;
}

void ins_end(int val)
{
  if(isfull())
  printf("\nOVERFLOW\n");
  else
  {
   if(front==-1)
     front=0;
  
    rear++;
    q[rear]=val;
    printf("%d INSERTED",val);
   }
  
}
void ins_beg(int val)
{
  if(front==-1)
  {
    front=0;
    q[++rear]=val;
    printf("%d INSERTED",val);
  }
  else if(front!=0)
  {
   q[--front]=val;
   printf("%d INSERTED",val);
  }
  else
  printf("INSERTION NOT POSSIBLE\n");
   
}
void del_front()
{
  if(isempty())
  printf("\n UNDERFLOW\n");
   else
   { 
     printf("%d DEQUEUED\n",q[front]);
     front++;
     
     if(front > rear)
     {
      front=-1;
      rear=-1;
     }
    } 
  
}
void del_end()
{
  if(isempty())
  printf("\n UNDERFLOW\n");
  else
  {
      printf("%d DEQUEUED",q[rear]);
      if(front==rear)
      front=rear=-1;
      else
      rear--;
  }
}
void display()
{
 int i;
 if(isempty())
  printf("\nEMPTY QUEUE\n");
 else
 {
 printf("\nQUEUE\n");
 for(i=front;i<=rear;i++)
 printf("%d  ",q[i]);
 printf("\nfront:%d",front);
 printf(" rear:%d",rear);
 printf("\n");
 }
}


void main()
{
int ch;
  int a,x;
  do
  {
   printf("\nDoubly Ended Queue\n");      
   printf("Enter choice...\n"); 
   printf("1.INSERT AT END\n");
   printf("2.INSERT AT FRONT\n");
   printf("3.DELETE AT FRONT\n");
   printf("4.DELETE AT END\n");
   printf("5.DISPLAY\n");
   printf("6.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: printf("Enter val to enter Queue:");
              scanf("%d",&x);
              ins_end(x);
              printf("\n");
              break;
      case 2: printf("Enter val to enter Queue:");
              scanf("%d",&x);
              ins_beg(x);
              printf("\n");
              break;
      case 3: del_front();
              printf("\n");
              break; 
      case 4: del_end();
              printf("\n");
              break;           
      case 5: display();
              printf("\n");
              break;     
           
    }
  }while(ch!=6);
}

