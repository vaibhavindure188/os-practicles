#include <bits/stdc++.h>
using namespace std;

int main()
{
    int memoryArr[5] = {100, 500, 200, 300, 600};
    int processArr[4] = {212, 417, 112, 100};

    
    int ans[4] = {-1};
    for(int i = 0;i<4;i++){
        int ind = -1;
        int flag = 0;
        int mini = INT_MAX;
        for(int j = 0;j<5;j++){
            if(memoryArr[j] >= processArr[i]){
                if(mini > memoryArr[j]){
                    mini = memoryArr[j];
                    ind = j;
                    flag = 1;
                }
            }
        }

        if(flag == 0) cout<<"process "<<i<<"th  is not allocated to any block"<<endl;
        else{
            ans[i] = ind;
            memoryArr[ind] = memoryArr[ind] - processArr[i];
        }
    }


    cout<<" zero based indexing "<<endl;
    for(int i = 0;i<4;i++){
        cout<<"process "<<i<<"th  memory block : "<<ans[i]<<endl;
    }



}