#include<stdio.h>
int pf=0,h=0;
int front=-1;
int rear=-1;
void Enqueue(int queue[],int f,int val)
{
int flag=0;
  for(int i=0;i<f;i++)
  {
    if(queue[i]==val)
    {
      h++;
      flag=1;
      break;
    }
  }
  if(flag!=1)
  {
    rear=(rear+1)%f;
    queue[rear]=val;
    pf++;
    for(int i=0;i<f;i++)
    {
       printf("%d \n",queue[i]);
    }
       printf("\n");
  }
}
int main()
{
int n,f;
printf("enter string length");
scanf("%d",&n);
int a[n];
printf("enter reference string");
for(int i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}
printf("enter frames");
scanf("%d",&f);
int queue[f];
for(int i=0;i<n;i++)
{
  Enqueue(queue,f,a[i]);
}
  printf(" page faults %d \n",pf);
  printf("hits%d",h);
}


