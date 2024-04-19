#include <bits/stdc++.h>
using namespace std;

int main()
{

    int disc = 199;
    int trackNo[7] = {82,170,43,140,24,16,190};

    int R_W_head = 50;
    int sum = 0;
    for(int i = 0;i<6;i++){
        sum += abs(trackNo[i+1]-trackNo[i]);
    }
    sum += abs(trackNo[0] - R_W_head);

    
    cout<<"Total No of movement that Read write head covered : "<<sum<<endl;
    
}
