#include<bits/stdc++.h>
using namespace std;

struct process{
    string id;
    int arrivaltime;
    int bursttime;
    int completiontime;
    int turnaroundtime;
    int waittime;
    int temp;
};

void premptivepriority(struct process p[],int n)
{

  for(int i=0;i<n;i++)
    {
    p[i].temp=p[i].bursttime;
    }
    int time=0;
    int completed=0;
    while(completed<n)
    {
        int selected_process=-1;
        int higharrival=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(p[i].arrivaltime<=time && p[i].arrivaltime<higharrival && p[i].bursttime>0)
            {
                higharrival=p[i].arrivaltime;
                selected_process=i;
            }
        }
        if(selected_process==-1) 
        {
            time++;
        }
        else
        {
                time+=p[selected_process].bursttime;
                p[selected_process].completiontime=time;
                p[selected_process].turnaroundtime=p[selected_process].completiontime-p[selected_process].arrivaltime;
                p[selected_process].waittime=p[selected_process].turnaroundtime-p[selected_process].bursttime;
                completed++;
                p[selected_process].bursttime=0;
        }
    }

    cout<<"Id  " <<"ARR " <<"BT  " <<"CT "<<"TAT " <<"WT "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<p[i].id<<"   "<<p[i].arrivaltime<<"  " <<p[i].temp<<"  "<<p[i].completiontime <<"   "<<p[i].turnaroundtime<<"   "<<p[i].waittime<<" "<<endl;
    }
}


int main()
{
    int n;
    string s;
    cout<<"Enter no:of Processors:"<<endl;
    cin >>n;
    struct process p[n];
    cout<<"Enter ProID  Arrival  Burst "<<endl;
    for(int i=0;i<n;i++)
    {
        //cout<<"Enter the Processor Id:"<<endl;
        cin >>p[i].id;
      //  cout<<"Enter its arrival time:"<<endl;
        cin >>p[i].arrivaltime;
        //cout<<"Enter its burst time:"<<endl;
        cin >>p[i].bursttime;
        
    }
    
    premptivepriority(p,n);
}

