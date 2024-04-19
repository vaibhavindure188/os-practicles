#include<bits/stdc++.h>


using namespace std;
class p{
    public:
    int pid;
    int arrival_time;
    int burst_time;

    p(int pid , int arrival_time, int burst_time){
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;
        this->pid = pid;
    }

    p(){}
};

bool cmp(p obj1, p obj2){
    return obj1.arrival_time < obj2.arrival_time;
}
int main()
{
    p * arr = new p[5];

    for(int i  =0 ;i<5;i++){
        cout<<"insert pid :";
        int pid;
        cin>>pid;
        cout<<"insert arrival time :";
        int arrival;
        cin>>arrival;
        cout<<"insert burst time :";
        int burst;
        cin>>burst;

        arr[i] = p(pid, arrival, burst);
        
    }

    sort(arr, arr+5, cmp);

    
    int flag = 0;
    int completion[5];
    for(int i =0;i<5;i++){
        if(flag == 0){
            int sum = arr[i].arrival_time + arr[i].burst_time;
            completion[i] = sum;
            flag = 1;
        }
        else{
            if(completion[i-1] < arr[i].arrival_time){
                completion[i] = arr[i].arrival_time + arr[i].burst_time;
            }
            else{
                completion[i] = completion[i-1] + arr[i].burst_time;
            }
        }
    }

    

    // calculating turnarround time 
    int turnaround_time[5];
    for(int i =0;i<5;i++){
        turnaround_time[i] = completion[i] - arr[i].arrival_time;
    }

    // calculating waiting time
    int waiting_time[5];
    for(int i =0;i<5;i++){
        waiting_time[i] = turnaround_time[i] - arr[i].burst_time;
    }

    cout<<"comletion times are as folows :"<<endl;
    for(int i =0;i<5;i++){
        cout<<completion[i]<<endl;

    }
    float sum = 0;
    cout<<"turnarround times are as folows :"<<endl;
    for(int i =0;i<5;i++){
        cout<<turnaround_time[i]<<endl;
        sum += turnaround_time[i];
    }
    float sum2 = 0;
    cout<<"waiting times are as folows :"<<endl;
    for(int i =0;i<5;i++){
        cout<<waiting_time[i]<<endl;
        sum2 += waiting_time[i];
    }

    // calculating avg wating time and avg turnarround time

    float avg_wt_time = float(sum2/5);
    float avg_tt_time = float(sum /5);
    cout<<"sum waiting time : "<<sum2<<endl;
    cout<<"sum turnaround time : "<<sum<<endl;
    cout<<"avg waiting time : "<<avg_wt_time<<endl;
    cout<<"avg turnaround time : "<<avg_tt_time<<endl;






    // int pid[5];
    // int arrivals[5];
    // int burstTime[5];
    
    // // cout<<"enter pid of processes"<<endl;
    // // for(int i =0;i<5;i++){
    // //     cin>>pid[i];
    // // }
    
    // map<int,int> arr_burst;
    
    // cout<<"enter arrival time and burst time of processes"<<endl;
    // for(int i =0;i<5;i++){
    //     cin>>arrivals[i];
    //     cin>>arr_burst[arrivals[i]];
    // }
    
    // sort(arrivals , arrivals+5);
    // cout<<"now printing mapping "<<endl;
    // for(int i =0;i<5;i++){

    //     cout<<arrivals[i]<<"  "<<arr_burst[arrivals[i]]<<endl;
    // }
    // int completion[5];
    // int flag = 0;
    // for(int i= 0;i<5;i++)
    // {
    //     int sum = arrivals[i] + arr_burst[arrivals[i]];
    //     if(flag == 0){
    //         completion[i] = sum;
    //     }
        
    //     else{
    //         flag = 1;
    //         if(completion[i-1] < arrivals[i]){
    //             completion[i] = arrivals[i] + arr_burst[arrivals[i]];
    //         }
          
    //         else{
    //         completion[i] = completion[i-1] + arr_burst[arrivals[i]];
    //         }
          
          
    //     }
           
    // }
    //   cout<<"now printing completion "<<endl;
      
    //   for(int i =0;i<5;i++)
    //   {
    //     cout<<completion[i]<<endl;
    //   }

      return 0;

}
        