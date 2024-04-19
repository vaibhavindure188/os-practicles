#include <bits/stdc++.h>
using namespace std;

bool check(int arr1[], int arr2[]){
    for (int i = 0; i<3;i++){
        if(arr1[i] < arr2[i]){
            return false;
        }
    }
    return true;
}
int main(){
    int instA = 7, instB = 3, instC = 4;  // this is for unsafe state for safe state a = 7 b= 10 c =5
    int alloc[5][3] = { {0,1,0}, {2,0,0},{3,0,2},{2,1,1},{0,0,2} };
    int maxNeed[5][3] = { {7,5,3}, {3,2,2},{9,0,2},{2,2,2},{4,3,3} };
    int remaingNeed[5][3] ;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<3;j++){
            remaingNeed[i][j] = maxNeed[i][j] - alloc[i][j];
        }
    }
    int sum_of_A_Alloc = 0,sum_of_B_Alloc = 0,sum_of_C_Alloc = 0; 
    for(int i = 0;i<5;i++){
        
            sum_of_A_Alloc += alloc[i][0];
            sum_of_B_Alloc += alloc[i][1];
            sum_of_C_Alloc += alloc[i][2];
    }
    int avail[3] = {instA -sum_of_A_Alloc ,instB - sum_of_B_Alloc,instC -sum_of_C_Alloc};

    int count = 0;
    int finish[5] = {0};
    int ans[5] ; // to store sequence
    int ind=0;  // for just tracking index of final ans array
    int flag ;
    while(count != 5){
        flag = 0;
        for(int i = 0;i<5;i++){
            
            if(check(avail, remaingNeed[i]) && finish[i] == 0){
                flag = 1;
                finish[i] = 1;
                for(int j = 0;j<3;j++){
                    avail[j] = alloc[i][j] + avail[j];
                }
                ans[ind++] = i;
                count++;
            }
        }
        if(flag == 0) {
            cout<<"system is in unsafe state"<<endl;
            // cout<<count<<endl;
            // for(int i = 0;i < 1;i++){
            //     cout<<ans[i]<<"  ";
            // }
            return 0;
        }
    }

    cout<<"system is in safe state and the sequence is "<<endl;
    for(int i = 0;i < 5;i++){
        cout<<ans[i]<<"  ";
    }

}