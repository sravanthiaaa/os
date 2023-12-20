#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
   int n;
   int m;
   int sum=0;
   printf("enter size of array");
   scanf("%d",&n);
   int a[n];
   printf("enter the elements of array");
   for(int i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
   printf("enter the main");
   scanf("%d",&m);
   for(int i=0;i<n;i++)
   {
     if(i==0)
     {
       sum=sum+abs(a[i]-m);
     }
     else
     {
        sum=sum+abs(a[i-1]-a[i]);
     }
   }
   printf("%d",sum);
}
