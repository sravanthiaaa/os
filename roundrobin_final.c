
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int data;
struct node *next;
};
struct node *front=NULL,*rare=NULL,*temp;
void enque(int x)
{
temp=(struct node *)malloc(sizeof(struct node ));
if(temp==NULL)
{
printf("q is full");
}
else
{
temp->data=x;
temp->next=NULL;
if(front==NULL)
{
front=rare=temp;
}
else
{
rare->next=temp;
rare=temp;
}
}
}
int deque()
{
int x=-1;
if(front==NULL)
{
printf("q is empty");
}
else
{
x=front->data;
temp=front;
front=front->next;
free(temp);
}
return x;
}
void display(struct node *front)
{
temp=front;
while(temp)
{
printf("%d ",temp->data);
temp=temp->next;
}
}
bool isEmpty()
{
if(front==NULL)
{
return true;
}
return false;
}
void swap(int *a,int *b)
{
int temp = *a;
*a=*b;
*b=temp;
}
int addInQ(int at[],int bt[],int pt[],int time[],int k,int i)
{
while(at[i] <= time[k-1] && bt[i] != 0 && i<6)
{
enque(pt[i]);
i++;
}
return i;
}
bool check(int bt[])
{
for(int m =0;m<6;m++)
{
if(bt[m] != 0)
{
return true;
}
}
return false;
}
void main()
{
int pt[] = {1,2,3,4,5,6};
int at[] = {0,1,2,3,4,5};
int bt[] = {4,5,6,3,1,4};
int n=6;
int tq = 2;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(at[j] > at[j+1])
{
swap(&at[j],&at[j+1]);
swap(&bt[j],&bt[j+1]);
swap(&pt[j],&pt[j+1]);
}
}
}
for(int i=0;i<n;i++)
{
printf("%d %d %d \n",pt[i],at[i],bt[i]);
}
int k=0;
int time[30];
for(int j=0;j<30;j++)
{
time[j] = -1;
}
time[k++] = at[0];
if(bt[0] <= tq)
{
time[k] = time[k-1] + bt[0];
bt[0] =0;
k = k+1;
}
else if(bt[0] > tq)
{
time[k] = time[k-1] + tq;
bt[0] =bt[0]-tq;
k = k+1;
}
int i =1;
while(at[i] <= time[k-1] && bt[i] != 0 && i<6)
{
enque(pt[i]);
i++;
}
if(bt[0] != 0)
{
enque(pt[0]);
}
while(check(bt))
{
int curr = deque();
int x;
for(x =0;x<6;x++)
{
if(pt[x] == curr)
{
break;
}
}
if(bt[x] <= tq)
{
time[k] = time[k-1] + bt[x];
bt[x] =0;
k = k+1;
}
else if(bt[x] > tq)
{
time[k] = time[k-1]+tq;
bt[x] =bt[x]-tq;
k = k+1;
}
while(at[i] <= time[k-1] && bt[i] != 0 && i<6)
{
enque(pt[i]);
i++;
}
if(bt[x] != 0)
{
enque(pt[x]);
}
}
printf("\n");
for(int l =0;l<30 && time[l] != -1;l++)
{
printf("%d) %d \n",l,time[l]);
}
}
