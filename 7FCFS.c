#include<stdio.h>
#include<stdlib.h>
struct process{
	int pr,at,bt;
};
void sort(struct process p[],int n)
{   int i,j;
	for( i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(p[j].at>p[j+1].at)
			{
				struct process temp;
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
int main()
{
	struct process p[100];
	
	int n,i;
	float atat=0,awt=0;
	printf("enter no. of process: ");
	scanf("%d",&n);
//	p=(struct process*)malloc(n*sizeof(struct process));
	int ct[n],tat[n],wt[n];
	printf("enter process,arrival time,burst time: ");
	for( i=0;i<n;i++)
	{
		scanf("%d%d%d",&p[i].pr,&p[i].at,&p[i].bt);
	}
	sort(p,n);
	//for(int i=0;i<n;i++)
	//	printf("%d %d",p[i].at,p[i].bt);
	//printf("GanttChatt: ");
	ct[0]=p[0].at+p[0].bt;
	for( i=1;i<n;i++)
	{
		if(p[i].at<=ct[i-1])
		{
			ct[i]=ct[i-1]+p[i].bt;
		//	printf("P%d ",p[i].pr);
		}
		else
		{
			ct[i]=p[i].at+p[i].bt;
		//	printf("- ");
		}
	}
	
	for( i=0;i<n;i++)
	{
		tat[i]=ct[i]-p[i].at;
		wt[i]=tat[i]-p[i].bt;
		atat+=tat[i];
		awt+=wt[i];
	}
	
	printf("pr\tAT\tBT\tCT\tTAT\tWT\n");
	for( i=0;i<n;i++)
	{
		printf("p%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pr,p[i].at,p[i].bt,ct[i],tat[i],wt[i]);
	}
	printf("Average TAT: %f",atat/n);
	printf("Average WT: %f",awt/n);
}

