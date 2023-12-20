#include<iostream>
#include<string>
using namespace std;
void print(char arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
}
bool find(char ch,char arr[],int n){
		for(int i=0;i<n;i++){
		if(arr[i]==ch){
			return true;
		}
	}
	return false;	
}
int findi(char ch,char arr[],int n){
	for(int i=0;i<n;i++){
		if(arr[i]==ch){
			return i;
		}
	}
	return -1;
}
int findc(int i,int n,string s,char ch){
	if(s[i-n]!=ch){
		return s[i-n];
	}
	else{
		int y=i-n;
		while(s[y]==ch){
			y--;
		}
		return s[y];
	}
	return -1;	
}
int main(){
	cout<<"Enter the string:";
	string s;
	cin>>s;
	int n;
	int hi=0;
	int mi=0;
	char pc='/';
	cout<<"enter no.of frames";
	cin>>n;
	char arr[n];
	int h=0;	
     for(int i=0;i<s.length();i++){
     	char ch=s[i];
     	if(!find(ch,arr,n)){
     		if(h<n){
		    	arr[i]=ch;
		    	h++;
		}
		else{
			int k=findc(i,n,s,pc);
			int l=findi(k,arr,n);
		    	arr[l]=ch;
		}
		print(arr,n);
		mi++;	
     	}
     	else{
     		hi++;
     		cout<<"hitcase at ch"<<ch<<endl;
		print(arr,n);
	}
	cout<<endl;
	pc=ch;	
     }  
     cout<<"no.of pagefaults are"<<mi; 
}
