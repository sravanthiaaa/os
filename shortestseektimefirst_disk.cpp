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
    int visited[n];
    int i=0;
    while(i!=n){
        int mini=INT_MAX,index=-1;
        for(int j=0;j<n;j++){
            if(abs(disks[j]-curr)<mini&&disks[j]!=curr&&visited[j]!=1){
                mini=abs(disks[j]-curr);
                index=j;
                
            }
        }
        total+=abs(curr-disks[index]);
        curr=disks[index];
        visited[index]=1;
        i++;
    }
    cout<<total<<endl;
}