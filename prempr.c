#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct point{
	int at;
	int bt;
	int ct;
	int wt;
	int tat;
	int pr;
	int vis;
};//
int getp(struct point p[],int ct,int n)
{
	int min = INT_MIN;
	int x = -1;
	for(int i=0;i<n;i++)
	{
		if(p[i].at <= ct && p[i].vis != 1)
		{
			if(p[i].pr>min)//higher no.higher priority
			//< lower no.higher priority
			{
				min = p[i].pr;
				x = i;
			}
			else if(p[i].pr == min)
			{
				if(p[i].at<p[x].at)
				{
					x =i;
				}
			}
		}
	}
	return x;
}
void main()
{
	int n;
	printf("enter the no. of process: ");
	scanf("%d",&n);
	struct point p[n];
	for(int i=0;i<n;i++)
	{
		printf("enter at: ");
		scanf("%d",&p[i].at);
		printf("enter bt: ");
		scanf("%d",&p[i].bt);
		printf("enter priori: ");
		scanf("%d",&p[i].pr);
		p[i].vis = 0;
	}
	int ct =0;
	int count =0;
	int awt = 0;
	int atat =0;
	while(count<n)
	{
		int index = getp(p,ct,n);
		if(index != -1)
		{
			p[index].bt = p[index].bt -1;
			p[index].ct = ct + 1;
			if(p[index].bt ==0)
			{
				count++;
				p[index].vis =1;
			}
			p[index].tat = p[index].ct - p[index].at;
			p[index].wt = p[index].tat - p[index].bt;
			ct = p[index].ct;
			awt = awt + p[index].wt;
			atat = atat + p[index].tat;
			printf("P%d ",index+1);
		}
		else{
			printf("- ");
			ct = ct+1;
		}	
	}
	printf("\n");
	printf("at	bt	ct	wt	tat");
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d	%d	%d	%d	%d 	\n",p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
	}
}
