#include<stdio.h>
int sort(int a[100],int n)
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
int look(int p[100],int n,int h,int t)
{
  int sum=0;
  int dir;
  sort(p,n);
  printf("1.right  2.left");
  printf("enter the direction");
  scanf("%d",&dir);
  if(dir==1)
  {
    sum=(p[n-1]-h)+(p[n-1]-p[0]);
    printf("%d",sum);
  }
  else
  {
    sum=(h-p[0])+(p[n-1]-p[0]);
    printf("%d",sum);
  }
}
int main()
{
int t,h,n;
  printf("enter the track");
  scanf("%d",&t);
  printf("enter the string length");
  scanf("%d",&n);
  printf("enter the head");
  scanf("%d",&h);
  int p[n];
  printf("enter the processes");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  look(p,n,h,t);
}
