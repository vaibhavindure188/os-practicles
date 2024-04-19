#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pages[15] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 1, 2, 0};
    int frames[3] = {7,0,1};
    int pgFault = 3, pgHit = 0;
    int ind = -1;
    

    for(int i = 3;i<15;i++){
        int flag = 0;
        for(int j = 0;j<3;j++){
            if(frames[j] == pages[i]){
                pgHit++;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            int arr[3] = {-1,-1,-1};
            int count = 0;
            int m = i+1;
            while(count <=2 && m <15 ){
                if(frames[0] == pages[m]){
                    count++;
                    arr[0] = 1;
                }

                if(frames[1] == pages[m]){
                    count++;
                    arr[1] = 1;
                }

                if(frames[2] == pages[m]){
                    count++;
                    arr[2] = 1;
                }
                m++;
            }
            
            if(count == 2){
                for(int x = 0;x<3;x++){
                    if(arr[x] == -1){
                        frames[x] = pages[i];
                        pgFault++;
                    }
                }
            }
            else{
                if(arr[0] == -1)
                {
                    frames[0] = pages[i];
                    pgFault++;
                }
                
                else if(arr[1] == -1) {
                    frames[1] = pages[i];
                    pgFault++;
                }
                else{
                    frames[2] = pages[i];
                    pgFault++;
                }
            }
        }
        cout<<"for page "<<pages[i]<<" :  ";
        for(int i = 0;i<3;i++){
            cout<<frames[i]<<" ";
        }
        cout<<endl;
    }
    std::cout << "total page fault = " << pgFault << endl;
    std::cout << "total page Hit = " << pgHit << endl;
}
