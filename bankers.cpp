#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=5;
	int r=3;//resouses
	int a[5][3]={ {0,0,1},{3,0,0,},{1,0,1},{2,3,2},{0,0,3}};//p1p2p3p4p5 allocation
	int m[5][3]={{7,6,3},{3,2,2,},{8,0,2},{2,1,2},{5,2,3}};//max matrix
	int av[3]={2,3,2};
	int need[n][r];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<r;j++)
		{
		need[i][j]=m[i][j]-a[i][j];
		}
	}
	int f[n],ans[n],ind=0;
	for(int k=0;k<n;k++)
	{
		f[k]=0;
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(f[i]==0)
			{
				int flag=0;
				for(int j=0;j<r;j++)
				{
					if(need[i][j]>av[j])
					{
					flag=1;
					break;
					}
				}
				if(flag==0)
				{
					ans[ind++]=i;
					for(int y=0;y<r;y++)
					{
						av[y]+=a[i][y];
					}
					f[i]=1;
				}
				
			}
			
		}
	}			
	cout<<"the safe seq is :"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"p"<<ans[i]<<"->";
	}                      
	
return 0;	
}

