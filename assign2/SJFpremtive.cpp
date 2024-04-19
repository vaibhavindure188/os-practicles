#include<bits/stdc++.h>
using namespace std;
class np{
    public:
    char p_id;
    int arr_time;
    int burst_time;
};
static bool cmp(np obj1, np obj2){
    if(obj1.arr_time == obj2.arr_time) return obj1.burst_time < obj2.burst_time;
    return obj1.arr_time < obj2.arr_time;
}
int main(){
    np arr[4];

    for(int i =0;i<4;i++){
        cout<<"enter pid arrival time and burst time"<<endl;
        cin>>arr[i].p_id;
        cin>>arr[i].arr_time;
        cin>>arr[i].burst_time;
    }

    sort(arr, arr+4, cmp);

    // now calculating completion time

    int arrival_time[4];
    int burst_timeArr[4];
    for(int i = 0;i<4;i++){
        arrival_time[i] = arr[i].arr_time;
        burst_timeArr[i] = arr[i].burst_time;
    }

    int b_time  = 0;

    for(int i = 0;i<4;i++){
        b_time += arr[i].burst_time;
    }
    int i = 0;
    vector<np> gantt;
    while(b_time >0){

        
        b_time--;
        if(arr[0].burst_time != 0){
            int afterSort = arr[0].arr_time;
        gantt.push_back(arr[0]);
        arr[0].arr_time++;
        arr[0].burst_time--;

        int m = 1;

        while(m < 4 && afterSort == arr[m].arr_time){
            arr[m].arr_time++;
            m++;
        }

        }
        else{
            while(arr[i].burst_time <= 0 ){
                i++;
            }
            int afterSort = arr[i].arr_time;
            gantt.push_back(arr[i]);
            arr[i].arr_time++;
            arr[i].burst_time--;

            for(int j = 0;j<i;j++){
            arr[j].arr_time++;
            }
            int m = i+1;
            while(m < 4 && afterSort == arr[m].arr_time){
            arr[m].arr_time++;
            m++;
        }

        }

        

        sort(arr, arr+4, cmp);

    }

    for(int j = 0;j<gantt.size();j++){
        // cout<<"pid : "<<gantt[j].p_id<<endl;
    }

    map<char, int> pid_cTime;
    for(int j = gantt.size() -1 ;j >=0;j--){
        if(pid_cTime.find(gantt[j].p_id)  == pid_cTime.end())
         pid_cTime[gantt[j].p_id] = j+1;
    }

// calculating completion time
   cout<<"printing completion time"<<endl;
    for(auto it : pid_cTime){
        cout<<it.first<<"  "<<it.second<<endl;
    }

    // calculating turn arround time 

    int tt[4];
    int j = 0;
    cout<<"printing turnarround time : "<<endl;
   for(auto it : pid_cTime){
        
        tt[j]  = it.second - arrival_time[j];
        cout<<it.first<<"  "<<tt[j]<<endl;
        j++;
    }
    int totalTT = 0;
    // calculating  total sum of turnarround time
    for(int k = 0;k<4;k++){
        totalTT += tt[k];
    }

    cout<<"avg turnarround time : "<<float(totalTT)/4<<endl;


    // now calculating waiting time :

    int waiting_time[4];
    int wt = 0;
    for(int i = 0;i<4;i++){
        waiting_time[i] = tt[i] - burst_timeArr[i];
        wt += waiting_time[i];

    }

    cout<<"average waiting time : "<<float(wt)/4<<endl;


}
