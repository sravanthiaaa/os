#include<stdio.h>
struct point{
int a;
int b;
};
struct point p[100];
int sort(int n)
{
struct point t;
  for(int i=0;i<n-1;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
        if(p[j].a>p[j+1].a)
        {
           t=p[j];
           p[j]=p[j+1];
           p[j+1]=t;
         }
     }
   }
   printf("sorted arrival time");
   for(int i=0;i<n;i++)
   {
     printf("%d %d \n",p[i].a,p[i].b);
   }
}
int C(int n)
{
int c[n];
 for(int i=0;i<n;i++)
 {
   if(i==0 || c[i-1]<p[i].a)
   {
      c[i]=p[i].a+p[i].b;
   }
   else
   {
     c[i]=c[i-1]+p[i].b;
   }
  }
printf("completion time");
for(int i=0;i<n;i++)
{
  printf("%d \t",c[i]);
}
printf("\n");
printf("turn arount time");
int TAT[n];
   for(int i=0;i<n;i++)
   {
      printf("%d\t",TAT[i]=c[i]-p[i].a);
   }
printf("\n");
printf("turn arount time");
int WT[n];
  for(int i=0;i<n;i++)
  {
    printf("%d \n",WT[i]=TAT[i]-p[i].b);
  }
int ATAT=0;
for(int i=0;i<n;i++)
{
  ATAT+=TAT[i];
}
printf("average tat is %d \n",ATAT/n);
int AWT=0;
for(int i=0;i<n;i++)
{
  AWT+=WT[i];
}
printf("average tat is %d \n",AWT/n);
}
int main()
{
int n;
printf("enter the processor size");
scanf("%d",&n);
printf("enter the arrival time and brust time ");
for(int i=0;i<n;i++)
{
  scanf("%d %d",&p[i].a,&p[i].b);
}
sort(n);	
C(n);
}


