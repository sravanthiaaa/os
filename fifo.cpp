#include<bits/stdc++.h>
using namespace std;
bool find(queue<int>q,int x){
	queue<int>temp;
	bool flag=false;
	while(!q.empty()){
		int y=q.front();
		if(y==x){
			
			flag=true;
		}
		q.pop();
		temp.push(y);
	}
	while(!temp.empty()){
		q.push(temp.front());
		temp.pop();
	}
	if(flag) return true;
	return false;
}
int main(){
	int framesize;
	int hit=0,pagefault=0;
	cin>>framesize;
	queue<int>v;
	int n;
	cin>>n;
	int capacity=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(find(v,x)){
			hit++;
		}
		else{
			
			if(!v.empty()&&capacity==framesize)
			{
				v.pop();
				capacity--;
			}
			v.push(x);
			capacity++;
			pagefault++;
		}
	}
	cout<<"page faults are:"<<pagefault<<endl;
	cout<<"Page hits are:"<<hit<<endl;
	cout<<"hit ratio="<<(float)hit/n<<endl;
}
