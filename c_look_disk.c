#include<stdio.h>
#include<limits.h>
int abs(int x)
{
if(x<0)
return -x;
else
return x;
}
int main()
{
 int i,j,min=INT_MAX,max=INT_MIN,head,limit,n,sum=0;
 
 printf("enter the n :");
 scanf("%d",&n);
 printf("enter the head :");
 scanf("%d",&head);
 
 printf("enter the limit :");
 scanf("%d",&limit);
 int s[n];
 for(i=0;i<n;i++)
  {
   scanf("%d",&s[i]);
  }
  
  for(i=0;i<n;i++)
 {
  if(s[i]<min)
  {
   min=s[i];
   }
}
printf("min is %d",min);

 for(i=0;i<n;i++)
 {
  if(s[i]>max)
  {
   max=s[i];
   }
}
printf(" max is %d\n",max);
int max1=1;
for(i=0;i<n;i++)
{
if(s[i]<head && s[i]>max1)
{
max1=s[i];
}
}

sum=abs(head-max)+abs(max-min)+abs(max1-min);


printf("heads are : %d",sum);


}
