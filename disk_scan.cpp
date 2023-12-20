#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s=0;
	cout<<"enter the number of elements:";
	cin>>n;
	int a[n];
	cout<<"enter the elements:";
	for(int i=0;i<n;i++)
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
	for(int i=0;i<n;i++)
	{
	cout<<a[i]<<" ";
	}
	cout<<endl;
	int ind;
	for(int i=0;i<n;i++)
	{
	if(a[i]>h)
	{
		ind=i;
		break;
	}
	}
	//right to left
	//cout<<ind;
         /* s=abs(a[ind]-h);
          int i;
	for( i=ind;i<n-1;i++)
	{
	s=s+abs(a[i]-a[i+1]);
	}
	s=s+abs(a[i]-(r-1));
	int t=r-1;
	for(int i=ind-1;i>=0;i--)
	{
		s=s+abs(a[i]-t);
		t=a[i];
	}
	cout<<"sum "<<s<<endl;
	}
	*/
	//left to right
	s=abs(a[ind-1]-h);
	for(int i=ind-1;i>=1;i--)
	{
		s=s+abs(a[i]-a[i-1]);
	}
	s=s+a[0];
	//s=s+r-1;
	int temp=0;
	for(int i=ind;i<n;i++)
	{
		s=s+abs(a[i]-temp);
		temp=a[i];
	}
	cout<<"sum "<<s;
}
	
	
