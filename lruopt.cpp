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
int findc(int i,int n,string s,char arr[]){
	int i1=-1;
	int i2=-1;
	int i3=-1;
	for(int k=i;k<s.length();k++){
		char ch=s[k];
		if(ch==arr[0] && i1==-1){
			i1=k;
		}
		else if(ch==arr[1] && i2==-1){
			i2=k;
		}
		else if(ch==arr[2] && i3==-1){
			i3=k;
		}	
	}
	if(i1==-1){
		return arr[0];
	}
	else if(i2==-1){
		return arr[1];
	}
	else if(i3==-1){
		return arr[2];
	}
	else{
		int maxi=max(max(i1,i2),i3);
		return s[maxi];
	}	
}
int main(){
	cout<<"Enter the string:";
	string s;
	cin>>s;
	int n;
	int hi=0;
	int mi=0;
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
			int k=findc(i,n,s,arr);
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
     }  
     cout<<"no.of pagefaults are"<<mi; 
}
