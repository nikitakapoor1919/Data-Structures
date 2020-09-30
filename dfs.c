#include<stdio.h>
int v=6,e,i,j;
int a[20][20]={{0,0,0,0,0,1},{0,0,1,0,0,1},{0,0,0,1,1,1},
              {0,0,1,0,1,0},{0,0,0,1,0,1},{0,1,0,1,1,0}};
int stack[20],top=-1;
int visited[20];

int isEmpty()
{
 if(top==-1)
 return 1;
 else return 0;
}

int isFull()
{
 if(top==v-1)
 return 1;
 else
 return 0;
}
void push(int item)
{
 if(!isFull())
 {
  stack[++top]=item;
 }
}
int pop()
{
 if(!isEmpty())
 {
  return stack[top--];
 }
}


void dfs()
{
 for(int i=0;i<v;i++)
 visited[i]=0;
 for(int i=0;i<v;i++)
 {
   if(visited[i]==0)
   {
    push(i);
    visited[i]=1;
    for(int j=0;j<v;j++)
    {
      if(a[i][j]==1)
      {
      int a=pop(i);
      printf("%d->",a);
      push(j);
      visited[j]=1;
      }
    }
   }
 }

}
void main()
{
  dfs();
}
