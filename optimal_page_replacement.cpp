#include<bits/stdc++.h>
using namespace std;
int finddist(vector<pair<int,int>>v,int curr,int pages[],int n){
	int dist[v.size()]={INT_MAX};
	for(int i=0;i<v.size();i++){
		int count=0;
		for(int j=curr;j<n;j++){
			count++;
			if(v[i].first==pages[j]){
				dist[i]=count;
				break;
			}
		}
	}
	int maxi=INT_MIN,index=-1;
	for(int i=0;i<v.size();i++){
		if(dist[i]>maxi){
			maxi=dist[i];
			index=i;
		}

	}
	return index;
}
int main(){
	int framesize;
	cin>>framesize;
	vector<pair<int,int>>v(framesize);
	int n;
	cin>>n;
	int pages[n];
	int pf=0,hit=0;
	for(int i=0;i<n;i++){
		cin>>pages[i];
	}
	int time=0;
	pf+=framesize;
	for(int i=0;i<framesize;i++){
		v[i].first=pages[i];
		v[i].second=time;
		time++;
	}
	for(int i=framesize;i<n;i++){
		bool flag=false;
		for(int j=0;j<v.size();j++){
			if(v[j].first==pages[i]){
			hit++;
				v[j].second=time;
				flag=true;
				break;
			}
		}
		if(!flag){
		pf++;
		int index=finddist(v,i,pages,n);
			v[index].first=pages[i];
			v[index].second=time;
			
		}
		time++;
	}
	cout<<"page fault:"<<pf<<endl;
	cout<<"hits:"<<hit<<endl;
}