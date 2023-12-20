#include<bits/stdc++.h>
using namespace std;

bool search(vector<int> &frame,int key)
{
    for(int i = 0 ; i < frame.size() ; i ++)
    {
        if(frame[i] == key) return true;
    }
    return false;
}

int nearFuture(vector<int>& frame,vector<int>& arr,int index)
{
    int replace = 0;
    int farthest = index - 1;
    for(int i = 0 ; i < frame.size() ; i ++)
    {
        int f = 0;
        for(int j = index ; j < arr.size() ; j ++)
        {
            if(frame[i] == arr[j])
            {
                f = 1;
                if(j > farthest)
                { 
                    replace = i;
                    farthest = j;
                }
                break;
            }
        }
        if(f == 0) return i;
    }
    return replace;
}

int main() 
{
    int n;
    cin >>n;

    vector<int> arr;

    for(int i = 0 ; i < n ; i ++)
    {
        int x;
        cin >>x;
        arr.push_back(x);
    }

    int capacity;
    cin >>capacity;
    int pageHits = 0;
    int pagefaults = 0;
    vector<int> frame;

    for(int i = 0 ; i < n ; i ++)
    {
        if(search(frame,arr[i]))
        {
            pageHits ++;
        }
        else
        {
            pagefaults ++;
            if(frame.size() < capacity) frame.push_back(arr[i]);
            else
            {
                int replace = nearFuture(frame,arr,i+1);
                frame[replace] = arr[i];
            }
        }
        for(int i = 0 ; i < frame.size() ; i ++)
        {
            cout<<frame[i]<<" ";
        }
        cout<<endl;
    }
    cout<<"PageHits :"<<pageHits<<" PageFaults :"<<pagefaults<<" ";

}