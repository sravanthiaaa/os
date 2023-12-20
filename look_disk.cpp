#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int disks[n];
    for(int i=0;i<n;i++){
        cin>>disks[i];
    }
    int start,end;
    cin>>start>>end;
    int head;
    cin>>head;
    int time=0,total=0;
    int curr=head,i=0;
    sort(disks,disks+n);
    for(i=0;i<n;i++){
        if(disks[i]>head) break;
    }
    total=(abs(disks[n-1]-head));
    cout<<"The order of the disks is as following: "<<endl;
    
    if(disks[i-1]!=head){
        total+=(abs(disks[n-1]-disks[0]));
        for(int j=i;j<n;j++){
        cout<<disks[j]<<" ";
    }
    for(int j=i-1;j>=0;j--){
        cout<<disks[j]<<" ";
    }
    }else{
        total+=(abs(disks[n-1]-disks[0]));
        for(int j=i-1;j<n;j++){
        cout<<disks[j]<<" ";
    }
    for(int j=i-2;j>=0;j--){
        cout<<disks[j]<<" ";
    }
    }
    cout<<endl;
    cout<<total<<endl;
    
}