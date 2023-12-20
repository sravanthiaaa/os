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
        for(int j=0;j<blocks;j++){
            if(blocks_sizes[j]>=processes[i]&&visited[j]!=1){
                cout<<"process "<<i+1<<" is allocated in frame"<<j+1<<endl;
                blocks_sizes[j]-=processes[i];
                visited[j]=1;
                break;
            }
        }
    }
}