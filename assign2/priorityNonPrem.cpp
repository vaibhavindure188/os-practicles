#include<bits/stdc++.h>
using namespace std;
class np{
    public:
    char p_id;
    int arr_time;
    int burst_time;
    int priority;
};
static bool cmp(np obj1, np obj2){
    if(obj1.arr_time == obj2.arr_time) return obj1.priority < obj2.priority;
    return obj1.arr_time < obj2.arr_time;
}

static bool cmp2(np obj1, np obj2){
    if(obj1.priority == obj2.priority) return obj1.arr_time <= obj2.arr_time;
    return obj1.priority < obj2.priority;
}
int main(){
    np arr[5];

    for(int i =0;i<5;i++){
        cout<<"enter pid arrival time and burst time"<<endl;
        cin>>arr[i].p_id;
        cin>>arr[i].arr_time;
        cin>>arr[i].burst_time;
        cin>>arr[i].priority;
    }

    sort(arr, arr+5, cmp);

    // now calculating completion time

    vector<pair<np,int>> completion_order;

    vector<np> running;

    running.push_back(arr[0]);
    completion_order.push_back({arr[0], arr[0].burst_time});
    int i = 1;
    int current_time = running.front().burst_time;
    while(running.size() != 0){
        while(i < 5 && arr[i].arr_time <= current_time ){
            running.push_back(arr[i++]);
            
        }
        running.erase(running.begin());
        sort(running.begin(), running.end(), cmp2);
        current_time += running.front().burst_time;
        if(running.size() != 0)
        completion_order.push_back({running.front(), current_time});
        
    }

    // printing gantt chart 
    for(int j =0;j<completion_order.size();j++){
         cout<<"pid: "<<completion_order[j].first.p_id<<"  "<<completion_order[j].second<<endl;
    }

    // calculating completion time  
    map<char, int> completion_time;

    for(int j =0;j<completion_order.size();j++){
        completion_time[completion_order[j].first.p_id] = completion_order[j].second;

    }

    //  printing completion time 
    cout<<"printing completion time"<<endl;
    for(auto it : completion_time){
        cout<<"pid :"<<it.first<<"  "<<it.second<<endl;
    }

    // calculating turnarround time
    
    cout<<"calculating turnarround time"<<endl;
    int tt[5];
    int k = 0;
    int totalTT = 0;
    for(auto it : completion_time){
        tt[k] = it.second - arr[k].arr_time;
        cout<<it.first <<"  "<<tt[k]<<endl;
        totalTT += tt[k];
        k++;
    }
    
    // calculating waiting time
    cout<<"calculating waiting time"<<endl;
    int wt[5];
    int totalWt = 0;
    for(int l = 0;l<5;l++){
        wt[l] = tt[l] - arr[l].burst_time;
        cout<<arr[l].p_id <<"  "<<wt[l]<<endl;
       totalWt += wt[l];
    }

    cout<<"avg tt :"<<float(totalTT)/5<<endl;
    cout<<"avg wt :"<<float(totalWt)/5<<endl;

}