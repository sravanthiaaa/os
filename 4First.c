#include<stdio.h>
int First(int b[100],int p[100],int n,int n1)
{
int a[n];
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<n1;j++)
   {
      if(b[j]>=p[i])
      {
         printf("%d -%d \n",p[i],b[j]);
         b[j]=-1;
         p[i]=-1;
         break;
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    if(p[i]!=-1)
    {
      printf("%d -must wait \n",p[i]);
    }
  }
}  
int main()
{
  int n,n1;
  printf("enter the number of processors");
  scanf("%d",&n);
  int p[n];
  printf("enter the processors");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }
  printf("enter the number of blocks");
  scanf("%d",&n1);
  int b[n1];
  printf("enter the blocks");
  for(int i=0;i<n1;i++)
  {
     scanf("%d",&b[i]);
  }
  First(b,p,n,n1);
}

      
      
      
  
  
  
  
  
  
  
  
  
  
