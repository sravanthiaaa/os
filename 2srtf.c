#include<stdio.h>
#include<limits.h>
struct point{
int at;
int bt;
int ct;
int tempbt;
int tat;
int wt;
};
int sum=0;
int n;
int srtf(struct point p[],int CT,int n)
{
  int x=-1;
  int min=INT_MAX;
  for(int i=0;i<n;i++)
  {
      if(p[i].at<=CT && p[i].bt!=0)
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
printf("enter the processor size");
scanf("%d",&n);
struct point p[n];
printf("enter the arrival time and brust time ");
for(int i=0;i<n;i++)
{
  scanf("%d %d",&p[i].at,&p[i].bt);
  p[i].tempbt=p[i].bt;
}	
int CT=0;
int k=0;
int sum=0;
for(int i=0;i<n;i++)
{
   sum=sum+p[i].bt;
}
while(k<sum)
{
   int index=srtf(p,CT,n);
   if(index!=-1)
   {
      p[index].ct=CT+1;
      p[index].bt=p[index].bt-1;
      k++;
      CT=p[index].ct;
      //printf("%d",index+1);//ghan chat
   }
   else
   {
      CT=CT+1;
      printf("-");
   }
}
for(int i=0;i<n;i++)
{
   p[i].tat=p[i].ct-p[i].at;
   p[i].wt=p[i].tat-p[i].tempbt;
   printf("\n");
   printf("%d %d %d %d %d",p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
   printf("\n");
}
}
