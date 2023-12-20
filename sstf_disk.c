#include<stdio.h>
#include<limits.h>

int abs(int num)
{
 if(num<0)
 {
 return -num;
 }
 else
 {
 return num;
 }
}

int main()
{
int i,j,seq,n,sum=0,h,index,x;

printf("enter the n value : ");
scanf("%d",&n);
int s[n];
printf("enter the seq");
for(i=0;i<n;i++)
{
scanf("%d",&s[i]);
}
printf("enter the head :");
scanf("%d",&h);

int k=0;
while(k<n)
{
int min=INT_MAX;
  for(i=0;i<n;i++)
  {
    x=abs(h-s[i]);
     if(x<min)
       {
         min=x;
         index=i;
       }
  }printf("%d ",s[index]);
  sum=sum+min;
  h=s[index];
  s[index]=9999;
  k++;
   
}
printf("the number of head rotates are : %d",sum);


}


