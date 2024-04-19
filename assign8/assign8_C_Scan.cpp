#include <bits/stdc++.h>
using namespace std;

int main()
{

    int disc = 199;
    int trackNo[7] = {82,170,43,140,24,16,190};

    int R_W_head = 50;
    sort(trackNo, trackNo+7);

    int firstTRavel = disc  - R_W_head;
    int secondTravel = disc ;

    int belowVal ;
    for(int i = 0;i<7;i++){
        if(trackNo[i] > R_W_head){
            belowVal = trackNo[i-1];
            break;
        }
    }
    int thridTravel = R_W_head - (R_W_head - belowVal) ; 

    cout<<"Total No of movement that Read write head covered : "<<firstTRavel + secondTravel+ thridTravel<<endl;
    cout<<firstTRavel<<endl;
    cout<<secondTravel<<endl;
    cout<<thridTravel<<endl;
}
