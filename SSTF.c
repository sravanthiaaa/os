#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main()
{
int n,m;
printf("enter the size of array");
scanf("%d",&n);
int a[n];
printf("enter the array elements");
for(int i=0;i<n;i++)
{
   scanf("%d",&a[i]);
}
printf("enter the main");
scanf("%d",&m);
int min=INT_MAX;
int t;
int index=m;
int s;
int index2;
int sum=0;
for(int i=0;i<n;i++)
{
min=INT_MAX;
for(int j=0;j<n;j++)
{
   t=abs(index-a[j]);
   if(t<=min)
   {
     min=t;
     s=a[j];
     index2=j;
   }  
}
printf("%d \n",s);
sum=sum+abs(index-s);
index=s;
index2=
a[index2]=9999;
}
printf("%d",sum);
}


