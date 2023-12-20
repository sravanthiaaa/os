#include<bits/stdc++.h>
using namespace std;
struct item{
    int stime;
    int btime;
    int ctime;
    int tatime;
    int wtime;
    int rtime;
    int allocationtime=0;
    int startingbtime;
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
        int x;
        cin>>x;
        arr[i].btime=x;
        arr[i].startingbtime=x;
    }
    int total=0;
    for(auto i:arr){
        total+=i.btime;
    }
    int count=0,start=0;
    while(count++<=total){
        int i=findmin(start,arr,n);
        arr[i].btime-=1;
        if(arr[i].allocationtime==0){
            if(arr[i].stime!=0)
            arr[i].allocationtime=start;
        }
        start++;
        if(arr[i].btime==0){
            visited[i]=1;
            arr[i].ctime=start;
            arr[i].tatime=arr[i].ctime-arr[i].stime;
            arr[i].wtime=arr[i].tatime-arr[i].startingbtime;
            arr[i].rtime=arr[i].allocationtime-arr[i].stime;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].stime<<"    "<<arr[i].btime<<"     "<<arr[i].ctime<<"       "<<arr[i].tatime<<"         "<<arr[i].wtime<<"      "<<arr[i].rtime<<"      "<<endl;
    }
}