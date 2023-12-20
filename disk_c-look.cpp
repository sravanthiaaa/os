#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s=0,i;
	cout<<"enter the number of elements:";
	cin>>n;
	int a[n];
	cout<<"enter the elements:";
	for( i=0;i<n;i++)
	{
	cin>>a[i];
	}
	sort(a,a+n);
	int h;
	cout<<"enter the head positin:";
	cin>>h;
	int r;
	cout<<"enyer the range:";
	cin>>r;
	for( i=0;i<n;i++)
	{
	cout<<a[i]<<" ";
	}
	cout<<endl;
	int ind;
	for( i=0;i<n;i++)
	{
	if(a[i]>h)
	{
		ind=i;
		break;
	}
	}
	//right to left
	/*s=abs(a[ind]-h);
	for(i=ind;i<n-1;i++)
	{
	s=s+abs(a[i]-a[i+1]);
	}
	//s=s+abs(a[n-1]-a[0]);
	int t=a[n-1];
	for(i=0;i<ind;i++)
	{
	s=s+abs(a[i]-t);
	t=a[i];
	}
	cout<<s;
	}
	*/
	//left to right
	s=abs(a[ind-1]-h);
	for(int i=ind-1;i>=1;i--)
	{
		s=s+abs(a[i]-a[i-1]);
	}
	s=s+abs(a[0]-a[n-1]);
	//s=s+r-1;
	int temp=a[n-1];
	for(int i=n-1;i>=ind;i--)
	{
		s=s+abs(a[i]-temp);
		temp=a[i];
	}
	cout<<"sum "<<s;
	}
	
