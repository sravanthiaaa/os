#include<stdio.h>
void firstFit(int b_size[],int m,int p_size[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++)
	{
		allocation[i] = -1;
	}
	int sum =0;
	for(int i=0;i<n;i++)
	{
		sum = sum + p_size[i];
	}
	int extfrag= sum;
	printf("internal fragmentation block wise: ");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(b_size[j] >= p_size[i] && b_size[j] != -1)
			{
				allocation[i] = j;
				b_size[j] = b_size[j]-p_size[i];
				printf("%d) %d ",j+1,b_size[j]);
				b_size[j] = -1;
				extfrag = extfrag - p_size[i];
				break; 
			}
		}
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d	%d	%d",i+1,p_size[i],allocation[i]+1);
		printf("\n");
	}
	printf("\n total external frgmentation: %d",extfrag);
	printf("\n");
}
void bestFit(int b_size[],int m,int p_size[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++)
	{
		allocation[i] = -1;
	}
	int sum =0;
	for(int i=0;i<n;i++)
	{
		sum = sum + p_size[i];
	}
	int extfrag= sum;
	printf("internal fragmentation of each block:\n");
	for(int i=0;i<n;i++)
	{
		int bestindex = -1;
		for(int j=0;j<m;j++)
		{
			if(b_size[j] >= p_size[i] && b_size[j] != -1)
			{
				if(bestindex == -1)
				{
					bestindex = j;
				}
				else if(b_size[bestindex] > b_size[j])
				{
					bestindex = j;
				}
			}
		}
		if(bestindex != -1)
		{
			allocation[i] = bestindex;
			b_size[bestindex] = b_size[bestindex] - p_size[i];
			extfrag = extfrag - p_size[i];
			printf("%d) %d ",bestindex+1,b_size[bestindex]);
			b_size[bestindex] =-1; 
		}
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d	%d	%d",i+1,p_size[i],allocation[i]+1);
		printf("\n");
	}
	printf("\n total external frgmentation: %d",extfrag);
}
void worstFit(int b_size[],int m,int p_size[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++)
	{
		allocation[i] = -1;
	}
	int sum =0;
	for(int i=0;i<n;i++)
	{
		sum = sum + p_size[i];
	}
	int extfrag= sum;
	printf("internal fragmentation of each block:\n");
	for(int i=0;i<n;i++)
	{
		int worstindex = -1;
		for(int j=0;j<m;j++)
		{
			if(b_size[j] >= p_size[i] && b_size[j] != -1)
			{
				if(worstindex == -1)
				{
					worstindex = j;
				}
				else if(b_size[worstindex] < b_size[j])
				{
					worstindex = j;
				}
			}
		}
		if(worstindex != -1)
		{
			allocation[i] = worstindex;
			b_size[worstindex] = b_size[worstindex] - p_size[i];
			extfrag = extfrag - p_size[i];
			printf("%d) %d ",worstindex+1,b_size[worstindex]);
			b_size[worstindex] =-1; 
		}
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d	%d	%d",i+1,p_size[i],allocation[i]+1);
		printf("\n");
	}
	printf("\n total external frgmentation: %d",extfrag);
}

void main()
{
	int m,n;
	int b_size[]= {100,500,100,300,600};
	int p_size[] = {212, 417, 112, 426};
	m = sizeof(b_size)/sizeof(b_size[0]);
	n = sizeof(p_size)/sizeof(p_size[0]);
	printf("first fit: \n");
	firstFit(b_size,m,p_size,n);
	int b1_size[]= {100,500,100,300,600};
	int p1_size[] = {212, 417, 112, 426};
	printf("best fit: \n");
	bestFit(b1_size,m,p1_size,n);
	int b2_size[]= {100,500,100,300,600};
	int p2_size[] = {212, 417, 112, 426};
	printf("worst fit: \n");
	worstFit(b2_size,m,p2_size,n);
}
