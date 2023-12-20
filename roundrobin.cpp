#include<bits/stdc++.h>
using namespace std;
struct item{
    int stime;
    int btime;
    int ctime;
    int tatime;
    int wtime;
    int rtime;
    int allocationtime=-1;
    int startingbtime;
    bool inq=false;
};
int visited[100]={0};
void getall(int start,queue<int>&q,item arr[],int n,int curr){
    for(int i=0;i<n;i++){
        if(i!=curr&&arr[i].stime<=start&&arr[i].btime!=0&&arr[i].inq==false){
            q.push(i);
            arr[i].inq=true;
        }
    }
}
int main(){
    int n;
    cout<<"enter the number of processes:";
    cin>>n;
    queue<int>q;
    item arr[n];
    cout<<"enter the arruve and bus time:";
    for(int i=0;i<n;i++){
        cin>>arr[i].stime;
        int x;
        cin>>x;
        arr[i].btime=x;
        arr[i].startingbtime=x;
    }
    cout<<"enter the time:";
    int timelapse;
    cin>>timelapse;
    int total=0;
    for(auto i:arr){
        total+=i.btime;
    }
    int count=0,start=0;
    q.push(0);
    arr[0].inq=true;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        if(arr[i].allocationtime==-1){
            arr[i].allocationtime=start;
        }
        if(arr[i].btime<=timelapse){
            if(!visited[i]) visited[i]=1;
            start+=arr[i].btime;
            arr[i].btime=0;
            arr[i].ctime=start;
            arr[i].tatime=arr[i].ctime-arr[i].stime;
            arr[i].wtime=arr[i].tatime-arr[i].startingbtime;
            arr[i].rtime=arr[i].allocationtime-arr[i].stime;
            cout<<arr[i].allocationtime<<" "<<arr[i].stime<<" ";
            cout<<i<<endl;
            getall(start,q,arr,n,i);
            continue;
        }
         arr[i].btime-=timelapse;
        start+=timelapse;
        getall(start,q,arr,n,i);
        q.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].stime<<"    "<<arr[i].startingbtime<<"     "<<arr[i].ctime<<"       "<<arr[i].tatime<<"         "<<arr[i].wtime<<"      "<<arr[i].rtime<<"      "<<endl;
    }
}
