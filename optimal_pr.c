#include<stdio.h>
#include<stdbool.h>
int greater(int c[],int size)
{
int pos,max=1;
for(int i=0;i<size;i++)
{
if(c[i]==-1)
{
return i;
}
}
for(int i=0;i<size;i++)
{
if(c[i]>max)
{
max=c[i];
pos=i;
}
}
return pos;
}


bool searchx(int b[],int f,int num)
{
for(int i=0;i<f;i++)
{
if(b[i] == num)
return true;
}
return false;
}
void print(int b[],int size)
{
for(int i=0;i<size;i++)
{
printf("%d ",b[i]);
}
printf("\n");
return;
}
int search(int key,int a[],int start,int size)
{
for(int i=start;i<size;i++)
{
if(a[i]==key)
{
return i;
}
}
return -1;
}
int main()
{
int n,r,i,j,f,count=0;
printf("enter the initial array size\n");
scanf("%d",&n);
int a[n];
printf("enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter the no. of frames\n");
scanf("%d",&f);
int b[f],c[f];
int hit =0;
for(j=0;j<f;j++)
{
b[j]=a[j];
}
print(b,f);
//j=0;
for(i=3;i<n;i++)
{
if(searchx(b,f,a[i]))
{
hit++;
}
else
{
for(j=0;j<f;j++)
{
c[j]=search(b[j],a,i,n);
}
r=greater(c,f);
b[r]=a[i];
print(b,f);
count++;
}
}
printf(" total no of faults are %d",count+3);
}
















