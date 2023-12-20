#include<bits/stdc++.h>
using namespace std;

void Bubblesort(vector<string>& Process,vector<int>& Burst,vector<int>& arrival)
{
    int n = arrival.size();
    for(int i = 0 ; i < n - 1 ; i ++)
    {
        for(int j = 0 ; j < n - i - 1; j ++)
        {
            if(arrival[j] > arrival[j+1])
            {
                swap(arrival[j],arrival[j+1]);
                swap(Process[j],Process[j+1]);
                swap(Burst[j],Burst[j+1]);
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter no:of Processors :";
    cin >>n;

    vector<int> arrival;
    vector<int> Burst;
    vector<string> Process;
   
    for(int i = 0 ; i < n ; i ++)
    {
        cout<<"\n Enter arrival and Burst time of "<<i+1<<"Processor:";
        int arr,burst;
        cin >>arr >>burst;
        arrival.push_back(arr);
        Burst.push_back(burst);
        string id = "P" +to_string(i+1);
        Process.push_back(id);
    }

    int quantum ;
    cout<<"Enter time Quantum:";
    cin >>quantum;

    Bubblesort(Process,Burst,arrival);

    vector<int> DummyBurst(Burst.begin(),Burst.end());

    queue<int> que;
    que.push(0);
    int time = arrival[0];
    vector<int> visited(n,0);
    visited[0] = 1;
    vector<int> completion(n);
    vector<int>turnaround(n);
    vector<int>waittime(n);

    while(!que.empty())
    {
        int index = que.front();
        que.pop();

        if(Burst[index] >= quantum) {
            Burst[index] -= quantum;
            time += quantum;
        }

        else {
            time += Burst[index];
            Burst[index] = 0;
        }

        for(int i = 0 ; i < n ; i ++)
        {
            if(arrival[i] <= time && Burst[i] > 0 && visited[i] == 0)
            {
                que.push(i);
                visited[i] = 1;
            }
        }

        if(Burst[index] > 0) {
            que.push(index);
            visited[index] = 1;
        }

        else {
            visited[index] = 0;
        }



        if(Burst[index] == 0) {
            completion[index] = time;
            turnaround[index] = time - arrival[index];
            waittime[index] = turnaround[index] - DummyBurst[index];
        }

    }
    cout<<endl;
    cout<<"Process"<<"\t"<<"Arrival Time"<<"\t"<<"Burst Time"<<"Completion Time"<<"\t"<<"Turn Around Time"<<"\t"<<"Waiting Time"<<endl;
    double avg = 0, tt = 0;
    for(int i=0; i<n; i++) {
        cout<<Process[i]<<"\t\t"<<arrival[i]<<"\t\t"<<DummyBurst[i]<<"\t\t"<<completion[i]<<"\t\t"<<turnaround[i]<<"\t\t"<<waittime[i]<<endl;
        avg = avg + waittime[i];
        tt = tt + turnaround[i];
    }
    cout<<"\n\nAverage waiting time ="<<avg/n;
    cout<<"  Average Turnaround time ="<<tt/n<<endl;

}