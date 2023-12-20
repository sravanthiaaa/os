#include<stdio.h>
#include<limits.h>
struct point{
  int at;
  int bt;
  int tat;
  int wt;
  int ct;
  int v;
};
int sjf(struct point p[],int CT,int n)
{
  int x=-1;
  int min=INT_MAX;
  for(int i=0;i<n;i++)
  {
    if(p[i].at<=CT && p[i].v!=1)
    {
       if(p[i].bt<min)
       {
         min=p[i].bt;
         x=i;
       }
       if(p[i].bt==min)
       {
          if(p[i].at<p[x].at)
          {
            x=i;
          }
       }
    }
 }
return x;
}
int main()
{
  int n;
  printf("enter the no.of processors");
  scanf("%d",&n);
  struct point p[n];
  printf("enter the arrival time and brust time");
  for(int i=0;i<n;i++)
  {
    scanf("%d %d",&p[i].at,&p[i].bt);
    p[i].v=0;
  }
  int CT=0;
  int k=0;//for incrementation to check the processor consider r not
  while(k<n)
  {
    int index=sjf(p,CT,n);
    if(index!=-1)
    {
      p[index].v=1;//visited
      p[index].ct=CT+p[index].bt;
      p[index].tat=p[index].ct-p[index].at;
      p[index].wt=p[index].tat-p[index].bt;
      k++;
      CT=p[index].ct;
    }
    else
    {
       CT=CT+1;
    }
 }
 for(int i=0;i<n;i++)
 {
   printf("ct %d  tat %d  wt %d ",p[i].ct,p[i].tat,p[i].wt);
   printf("\n");
 }
 printf("average tat");
 int sum=0;
 for(int i=0;i<n;i++)
 {
   sum=sum+p[i].tat;
 }
 printf("%d",sum/n);
 
 printf("average awt");
 int sum1=0;
 for(int i=0;i<n;i++)
 {
   sum1=sum1+p[i].wt;
 }
 printf("%d",sum1/n);
}
