#include<stdio.h>
#include<stdlib.h>
void sort(int a[100],int n)
{
int t;
  for(int i=0;i<n;i++)
  { 
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
      }
    }
  }
}
int scan(int p[100],int n,int t,int h)
{
  int dir;
  int sum=0;
  sort(p,n);
  printf("1=right ,2=left");
  scanf("%d",&dir);
  if(dir==1)
  {
    sum=((t-1)-h)+((t-1)-p[0]);
    printf("%d",sum);
  }
  else
  {
    sum=abs(h-0)+abs(0-p[n-1]);
    printf("%d",sum);
  }
}
int main()
{
int t,n,h;
  printf("enter the track");
  scanf("%d",&t);
  printf("enter the head");
  scanf("%d",&h);
  printf("enter the string length");
  scanf("%d",&n);
  int p[n];
  printf("enter the processes");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  scan(p,n,t,h);
}
  
  
