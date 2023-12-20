#include<bits/stdc++.h>
using namespace std;
int main()
{

	//int n=7,h=50;
	int n,h;
	cout<<"enter the number of elements";
	cin>>n;
	cout<<"\nenter the head position";
	cin>>h;
	int a[n];
	for(int i=0;i<n;i++)
	{
	cin>>a[i];
	}
	int s=0;
	//int a[7]={68,92,112,14,76,10,53};
	s=abs(a[0]-h);
	for(int i=1;i<n;i++)
	{
	s=s+abs(a[i]-a[i-1]);
	}
	cout<<"head moments are:"<<s;
	}
