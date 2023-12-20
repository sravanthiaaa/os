#include<bits/stdc++.h>
using namespace std;
struct item{
    int stime;
    int btime;
    int ctime;
    int tatime;
    int wtime;
};
static bool cmp(item a,item b){
    return a.stime<b.stime;
}
int main(){
    int n;
    cin>>n;
    item arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].stime;
        cin>>arr[i].btime;
    }
    sort(arr,arr+n,cmp);
    int start=0;
    for(int i=0;i<n;i++){
        arr[i].ctime=arr[i].btime+start;
        start+=arr[i].btime;
        arr[i].tatime=arr[i].ctime-arr[i].stime;
        arr[i].wtime=arr[i].tatime-arr[i].btime;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i].stime<<"    "<<arr[i].btime<<"     "<<arr[i].ctime<<"       "<<arr[i].tatime<<"         "<<arr[i].wtime<<"      "<<endl;
    }
}