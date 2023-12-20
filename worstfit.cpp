#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int processes[n];
    for(int i=0;i<n;i++){
        cin>>processes[i];
    }
    int blocks;
    cin>>blocks;
    int blocks_sizes[blocks];
    for(int i=0;i<blocks;i++){
        cin>>blocks_sizes[i];
    }
    int visited[blocks];
    for(int i=0;i<n;i++){
        int index=-1,maxi=INT_MIN;
        for(int j=0;j<blocks;j++){
            if(blocks_sizes[j]>=processes[i]&&visited[j]!=1&&maxi<(blocks_sizes[j]-processes[i])){
                maxi=blocks_sizes[j]-processes[i];
                index=j;
            }
        }
        if(index!=-1){
            cout<<"process "<<i+1<<" is allocated in frame"<<index+1<<endl;
            blocks_sizes[index]-=processes[i];
            visited[index]=1;
        }
    }
}