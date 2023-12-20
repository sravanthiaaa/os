#include<bits/stdc++.h>
using namespace std;
struct process{
    int at,bt,ct,priority,tat,wt;
};
static bool cmp(process p1,process p2){
    if(p1.at==p2.at) return p1.priority<p2.priority;
    return p1.at<p2.at;
}
int visited[100]={0};
int findmin(process arr[],int  start,int n){
    int mini=INT_MAX,index;
    for(int i=0;i<n;i++){
        if(visited[i]==0&&arr[i].at<=start&&arr[i].priority<mini){
            index=i;
            mini=arr[i].priority;
        }
    }
    return index;
}
int main(){
    cout<<"Enter no of processes:"<<endl;
    int n;
    cin>>n;
    process arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].priority>>arr[i].at>>arr[i].bt;
    }
    sort(arr,arr+n,cmp);
    int start=arr[0].at,total=0;
    for(int i=0;i<n;i++){
        total+=arr[i].bt;
    }
    int count=0;
    while(start<=total){
        int i=findmin(arr,start,n);
        visited[i]=1;
        start+=arr[i].bt;
        arr[i].ct=start;
        arr[i].tat=arr[i].ct-arr[i].at;
        arr[i].wt=arr[i].tat-arr[i].bt;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].at<<"    "<<arr[i].bt<<"     "<<arr[i].ct<<"       "<<arr[i].tat<<"         "<<arr[i].wt<<"      "<<endl;
    }
}
