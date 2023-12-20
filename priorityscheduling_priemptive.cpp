#include<bits/stdc++.h>
using namespace std;
struct process{
    int at,bt,ct,priority,tat,wt,allot=-1,rt,sbt;
};
int findmin(int start,process arr[],int n){
    int index=-1,mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i].bt!=0&&arr[i].at<=start&&mini>arr[i].priority){
                mini=arr[i].priority;
                index=i;
        }
    }
    return index;
}
static bool cmp(process p1,process p2){
    if(p1.at==p2.at) return p1.priority<p2.priority;
    return p1.at<p2.at;
}
int main(){
    int n;
    cin>>n;
    process arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].priority>>arr[i].at>>arr[i].bt;
        arr[i].sbt=arr[i].bt;
    }
    int start=0;
    sort(arr,arr+n,cmp);
    int total=0;
    for(process i:arr) total+=i.bt;
    int count=0;
    while(count++<=total){
        int i=findmin(start,arr,n);
        if(arr[i].allot==-1) arr[i].allot=start;
        arr[i].bt--;
        start++;
        if(arr[i].bt==0){
            arr[i].ct=start;
            arr[i].tat=arr[i].ct-arr[i].at;
            arr[i].wt=arr[i].tat-arr[i].sbt;
            arr[i].rt=arr[i].allot-arr[i].at;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].at<<"    "<<arr[i].bt<<"     "<<arr[i].ct<<"       "<<arr[i].tat<<"         "<<arr[i].wt<<"      "<<arr[i].rt<<"      "<<endl;
    }
}