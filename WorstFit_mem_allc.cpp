//vinay
//Worst Fit memorey Allocation
#include<bits/stdc++.h>
using namespace std;



void worstfit(vector<int>&mem,vector<int>&pro,int n,int m){

	vector<int>v(m,-1);//to store which procces occupied which block
	vector<int>a(n,-1);//to check memorey occupied or not
	for(int i=0;i<m;i++)//proccess traversal
	{
		int ma=INT_MIN;// to find max block
		int ind;
		bool f=false;
		for(int j=0;j<n;j++)//memorey traversal
		{
			if(pro[i]<=mem[j] && mem[j]>ma && a[j]==-1){
			    	ma=mem[j];//max block should fill first(that's why)
			    	ind=j;
			    	f=true;
				}
		}
		 if(f){
		 a[ind]=0;
		 v[i]=ind+1;
		  }
		}
		 cout<<"Process_Id \t"<<"Proccess_size\t "<<"Memorey_Block"<<endl;
		 for(int i=0;i<m;i++){
		 	cout<<"P"<<i+1<<"\t \t \t "<<pro[i]<<" \t \t \t";
		 			if(v[i]!=-1)cout<<"Block-"<<v[i]<<" ("<<mem[v[i]-1]<<")"<<endl;
		 			else cout<<"Not allotted"<<endl;
		 		}
		  
    }


int main()
{
	int n;
	cin>>n;//no of memorey blocks
	
	vector<int>mem(n);
	for(int i=0;i<n;i++)
	  cin>>mem[i];
	int m;
	cin>>m;// no of process
	vector<int>pro(m);

	
	for(int i=0;i<n;i++)
		cin>>pro[i];

	worstfit(mem,pro,n,m);
}