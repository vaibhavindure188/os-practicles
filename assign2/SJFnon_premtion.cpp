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
    int comletion_time[4];
    int flag = 0;
    for(int i =0;i<4;i++){
        if(flag == 0){
            comletion_time[i] = arr[i].burst_time + arr[i].arr_time;
            flag = 1 ;
        }

        else{
            if(arr[i].arr_time <= comletion_time[i-1]){
                comletion_time[i] = comletion_time[i-1] + arr[i].burst_time;
            }
            else{
                comletion_time[i] = arr[i].arr_time + arr[i].burst_time;
            }
        }
    }

    // now calculating turn arround time

    int tt[4];
    int sum_of_tt = 0;
    for(int i = 0;i<4;i++){
        tt[i] = comletion_time[i] - arr[i].arr_time;
        sum_of_tt += tt[i];
    }

    // now calculating waiting  time

    int wt[4];
    int sum_of_wt = 0;
    for(int i = 0;i<4;i++){
        wt[i] = tt[i] - arr[i].burst_time;
        sum_of_wt += wt[i];
    }

    // now calculating avg tt
      cout<<"avg of tt : "<<float(sum_of_tt)/4<<endl;

      cout<<"avg of wt  :"<<float(sum_of_wt)/4<<endl;

}
