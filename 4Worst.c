#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void sort(int a[],int n1)
{
int i,j,t;
for(i=0;i<n1;i++)
{
for(j=0;j<n1-i-1;j++)
{
if(a[j]<a[j+1])
{
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}
}
}
void worst(int p[100],int b[100],int n,int n1)
{
sort(b,n1);
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n1;j++)
     {
       if(p[i]<=b[j])
       {
          printf("%d- %d \n",p[i],b[j]);
          b[j]=-1;
          p[i]=-1;
          break;
       }
     }
     if(p[i]!=-1)
     printf("%d - must wait \n",p[i]);
   }
}
int main()
{
int n,n1;
  printf("enter the no.of processors");
  scanf("%d",&n);
  int p[n];
  printf("enter processes");
  for(int i=0;i<n;i++)
  {
     scanf("%d",&p[i]);
  }
  printf("enter the no.of blocks");
  scanf("%d",&n1);
  int b[n1];
  printf("enter blocks");
  for(int i=0;i<n1;i++)
  {
     scanf("%d",&b[i]);
  }
  worst(p,b,n,n1);
}
