#include<bits/stdc++.h>
using namespace std;

struct process{
    string id;
    int arrivaltime;
    int bursttime;
    int priority;
    int completiontime;
    int turnaroundtime;
    int waittime;
};

void premptivepriority(struct process p[],int n)
{
    int time=0;
    int remaining_process=n;
    while(remaining_process>0)
    {
        int selected_process=-1;
        int highpriority=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(p[i].arrivaltime<=time && p[i].priority<highpriority && p[i].bursttime>0)
            {
                highpriority=p[i].priority;
                selected_process=i;
            }
        }
        if(selected_process==-1)
        {
            time++;
        }
        else
        {
            p[selected_process].bursttime--;
            time++;
            if(p[selected_process].bursttime==0) 
            {
                remaining_process--;
                p[selected_process].completiontime=time;
                p[selected_process].turnaroundtime=p[selected_process].completiontime-p[selected_process].arrivaltime;
                p[selected_process].waittime=p[selected_process].turnaroundtime-p[selected_process].bursttime;
            }

        }
    }
    cout<<"Id  " <<"ARR" <<"  BT " <<" CT"<<" "<<"TAT" <<"  "<<"WT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<"   "<<p[i].arrivaltime<<"  " <<p[i].bursttime<<"  "<<p[i].completiontime <<"   "<<p[i].turnaroundtime<<"   "<<p[i].waittime<<" "<<endl;
    }
}


int main()
{
    int n;
    string s;
    cout<<"Enter no:of Processors:"<<endl;
    cin >>n;
    struct process p[n];
    cout<<"Enter ProID  Arrival  Burst  Priority"<<endl;
    for(int i=0;i<n;i++)
    {
        //cout<<"Enter the Processor Id:"<<endl;
        cin >>p[i].id;
      //  cout<<"Enter its arrival time:"<<endl;
        cin >>p[i].arrivaltime;
        //cout<<"Enter its burst time:"<<endl;
        cin >>p[i].bursttime;
        //cout<<"Enter its priority:"<<endl;
        cin >>p[i].priority;
    }
    premptivepriority(p,n);
}

