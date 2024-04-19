#include<bits/stdc++.h>
using namespace std;

class roundRobin{
    public:
    char p_id;
    int arr_time;
    int burst_time;
};
static bool cmp(roundRobin obj1, roundRobin obj2){
    
    return obj1.arr_time <= obj2.arr_time;
}

int main(){
    roundRobin arr[4];

    for(int i =0;i<4;i++){
        cout<<"enter pid arrival time and burst time"<<endl;
        cin>>arr[i].p_id;
        cin>>arr[i].arr_time;
        cin>>arr[i].burst_time;
    }

    sort(arr, arr+4, cmp);

    // now calculating completion time
    int comletion_time[4];

    queue<roundRobin> ready;
    vector<roundRobin> running;
    vector<int> compl_mapping;
    int index = 1;
    ready.push(arr[0]);
    int count = 0;
    int tq = 2;
    // compl_mapping.push_back(count);
    while(!ready.empty() && running.size() < 12){
        while(ready.front().burst_time <= 0) ready.pop();
            running.push_back(ready.front()) ;
            
            if(ready.front().burst_time >= tq){
                ready.front().burst_time -= tq; 
                
                
                for(int i = index;i<4;i++){
                    if(arr[i].arr_time <= count+2 ){
                        ready.push(arr[i]);
                        index++;
                    }
                }

                count = count + tq;
                compl_mapping.push_back(count);
                if(ready.front().burst_time > 0 )
                ready.push(ready.front());
                ready.pop();   
            }
            else{
                count += ready.front().burst_time;
                compl_mapping.push_back(count);
                ready.front().burst_time = 0;
                for(int i = index;i<4;i++){
                    if(arr[i].arr_time <= count ){
                        ready.push(arr[i]);
                        index++;
                    }
                }
                ready.pop();
            }
    }
    map<char, int> comletion_time2;
    int i = 0;
    for(auto it : running){
        cout<<"pid : "<<it.p_id<<"  count : "<<compl_mapping[i]<<endl;
        // now calculating completion time
        comletion_time2[it.p_id] = compl_mapping[i];
        i++;
    }



    

    for(const auto & pair : comletion_time2){
        cout<<"pid : "<<pair.first<<"completion time : "<<pair.second<<endl;
    }

    // now calculating turnarround time 

    int turnarround_time[4];
    int k = 0;
    for(const auto & pair : comletion_time2){
        cout<<"pid : "<<pair.first<<"completion time : "<<pair.second<<endl;

        turnarround_time[k] = pair.second - arr[k].arr_time;
        k++;
    }
    int totalTT = 0;
    int totalWT = 0;
    for(int j = 0;j<4;j++){
        cout<<"turnarround time : "<<turnarround_time[j]<<endl;
        totalTT += turnarround_time[j];
    }

    // now calculating waiting time 

    int waiting[4];

    for(int m = 0;m < 4;m++){
        waiting[m] = turnarround_time[m] - arr[m].burst_time;
        cout<<"waiting time : "<<waiting[m]<<endl;
        totalWT += waiting[m];
    }

    // 
    cout<<"avg Turnarround time :"<<float(totalTT)/4<<endl;
    cout<<"avg waiting time :"<<float(totalWT)/4<<endl;

   
}