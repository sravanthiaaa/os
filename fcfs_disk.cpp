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
    int curr=head;
    for(int i=0;i<n;i++){
        total+=abs(curr-disks[i]);
        curr=disks[i];
    }
    cout<<total<<endl;
}