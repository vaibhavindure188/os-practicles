#include <bits/stdc++.h>
using namespace std;

int main()
{
    int memoryArr[5] = {100, 500, 200, 300, 600};
    int processArr[4] = {212, 417, 112, 100};
    int fragmentedArr[5] = {0}; // in this array we will store the indixes of mem which are framgmented

    int flag = 0;
    int ind = -1;
    int visited[5] = {0};
    int pre = -1;
    int ans[4] = {-1};
    for (int i = 0; i < 4; i++)
    {

        do{
            ind = (ind+ 1) % 5;
            if(memoryArr[ind] >= processArr[i]){
                ans[i] = ind;
                memoryArr[ind] = memoryArr[ind] - processArr[i];
                flag = 1;
                break;
            }

        }while(ind != pre);
        pre = ind;
        if(flag == 0)
        {
                cout<<"process "<<i<<"th is not allocated"<<endl;
                
        }  
    

    }

    cout<<"one based indexing "<<endl;
    for(int i= 0;i<4;i++){
        cout<<"process : "<<i+1<<"  memory block : "<<ans[i]+1<<endl;
    }
}