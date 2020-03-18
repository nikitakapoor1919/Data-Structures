#include<stdio.h>
# define MAX 3
int front=-1,rear=-1;
int q[MAX];

int isfull()
{
  if(rear==MAX-1&&front==0||front==rear+1)
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

void enqueue(int val)
{
  if(isfull())
  printf("\nOVERFLOW\n");
  else
  {
   if(front==-1)
     front=0;
  
    rear= (rear+1)%MAX;
    q[rear]=val;
    printf("%d INSERTED\n",val);
   }
  
}
void dequeue()
{
  if(isempty())
  printf("\n UNDERFLOW\n");
   else
   { 
     printf("%d DEQUEUED\n",q[front]);
     if(front==rear)
     {
      front=-1;
      rear=-1;
     }
     else
     front=(front+1)%MAX;
    } 
}
void display()
{
 int i;
 if(isempty())
  printf("\n EMPTY QUEUE\n");
 else
 {
  printf("\nQUEUE\n");
  for(i=front;i!=rear;i=(i+1)%MAX)
  {
  printf("%d  ",q[i]);
  }
  printf("%d  ",q[i]);
  printf("\n front:%d",front);
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
   printf("\nCIRCULAR QUEUE\nEnter choice...\n"); 
   printf("1.ENQUEUE\n");
   printf("2.DEQUEUE\n");
   printf("3.DISPLAY\n");
   printf("4.EXIT\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: 
              printf("Enter val to enter Queue:");
              scanf("%d",&x);
              enqueue(x);
              printf("\n");
              break;
      case 2: dequeue();
              printf("\n");
              break;              
      case 3: display();
              printf("\n");
              break;     
           
    }
  }while(ch!=4);
}

