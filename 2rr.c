#include<stdio.h>
#include<stdlib.h>
#define max 100
int q[max];
int front=-1;
int rear=-1;
void enqueue(int n)
{
  if(front==-1&&rear==-1)
  {
    front=0;
    rear=0;
    q[rear]=n;
    }
  else if((rear+1)%max==front)
  {
    printf("queue is overflow");
  }
  else
  {
    rear=(rear+1)%max;
    q[rear]=n;
  }
 }
 int dequeue()
 {
    if(front==-1&&rear==-1)
    {
      printf("queue is underflow");
    }
    else if(front==rear)
    {int t=q[front];
      front=-1;
      rear=-1;
      return t;
    }
    else
    {
      int t=q[front];
      front=(front+1)%max;
      return t;
    }
   }
   int isempty()
   {
     if(front==-1&&rear==-1)
       return 1;
     return 0;
    }
    struct process{
     int at;
     int bt;
     int ct;
     int tat;
     int wt;
     int rt;
     int r;
     int inq;
     };
     int main()
     {
        int n;
        scanf("%d",&n);
     //   max=n;
        int t,i;
       scanf("%d",&t);
       struct process p[n];
       for(i=0;i<n;i++)
       {
         scanf("%d%d",&p[i].at,&p[i].bt);
         p[i].inq=0;
         p[i].r=p[i].bt;
       }
       int c=99999,j=-1,f=999999;
     /*  for(i=0;i<n;i++)
       {
           if(p[i].at<c)
           {
              c=p[i].at;
              j=i;
              f=p[i].bt;
            }
          }
          printf("%d\n",p[j].at);
          */
            for(i=0;i<n;i++)
      {
        for(j=0;j<n-1;j++)
        {
           if(p[j].at>p[j+1].at)
           {
             struct process temp=p[j];
             p[j]=p[j+1];
             p[j+1]=temp;
            }
          }
        }
        j=0;
        c=p[j].at;
          enqueue(j);
          p[j].rt=0;
         while(!isempty())
         {
            j=dequeue();
            p[j].inq=0;
            if(p[j].r==p[j].bt)
                  p[j].rt=c-p[j].at;
            if(p[j].bt<=t&&p[j].bt!=0)
            {
                 c=c+p[j].bt;
                 p[j].bt=0;
                 p[j].ct=c;
                 p[j].tat=p[j].ct-p[j].at;
                 p[j].wt=p[j].tat-p[j].r;
                
            }
            else
            {
               c=c+t;
               p[j].bt=p[j].bt-t;
             }
             for(i=0;i<n;i++)
             {
               if(p[i].at<=c&&p[i].bt!=0&&p[i].inq==0&&i!=j)
               {
                 enqueue(i);
                 p[i].inq=1;
                }
               }
               if(p[j].bt!=0)
               {
                 enqueue(j);
                 p[j].inq=1;
               }
           }
            for(i=0;i<n;i++)
              printf("%d %d %d %d %d %d\n",p[i].at,p[i].r,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
        }
                
