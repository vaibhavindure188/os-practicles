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
            int arr[3] ={-1,-1,-1};
            int count = 0;
            pgFault++;
            for(int m = i-1;m>=0 && count < 2;m--){
                if(pages[m] ==  frames[0]){
                    count++;
                    arr[0] = 1;
                }
                if(pages[m] ==  frames[1]){
                    count++;
                    arr[1] = 1;
                }
                if(pages[m] ==  frames[2]){
                    count++;
                    arr[2] = 1;
                }

            }
            for(int x = 0;x<3;x++){
                if(arr[x] == -1){
                    frames[x] = pages[i];
                    break;
                }
            }
            
        }

        cout<<"for "<<pages[i]<<" : ";
        for(int y = 0;y<3;y++){
            cout<<frames[y]<<"  ";
        }
        cout<<endl;
    }
    cout<<"total page Hit : "<<pgHit<<endl;
    cout<<"total page Fault : "<<pgFault<<endl;

}