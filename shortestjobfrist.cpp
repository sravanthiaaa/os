#include<bits/stdc++.h>
using namespace std;
struct item{
    int stime;
    int btime;
    int ctime;
    int tatime;
    int wtime;
};
int visited[100]={0};
int findmin(int start,item arr[],int n){
    int index=-1,mini=INT_MAX;
    for(int i=0;i<n;i++){
        if(!visited[i]&&arr[i].stime<=start&&mini>arr[i].btime){
            mini=arr[i].btime;
            index=i;
        }
    }
    return index;
}
int main(){
    int n;
    cin>>n;
    item arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].stime;
        cin>>arr[i].btime;
    }
    int start=0;
    int comptime=0;
    int count=0;
    while(count++<n){
        int i=findmin(start,arr,n);
        visited[i]=1;
        start+=arr[i].btime;
        arr[i].ctime=start;
        arr[i].tatime=arr[i].ctime-arr[i].stime;
        arr[i].wtime=arr[i].tatime-arr[i].btime;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].stime<<"    "<<arr[i].btime<<"     "<<arr[i].ctime<<"       "<<arr[i].tatime<<"         "<<arr[i].wtime<<"      "<<endl;
    }
}