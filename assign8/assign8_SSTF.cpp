#include <bits/stdc++.h>
using namespace std;

int main()
{

    int disc = 199;
    int trackNo[7] = {82,170,43,140,24,16,190};

    int R_W_head = 50;
    sort(trackNo, trackNo+7);

    int firstTRavel = R_W_head - trackNo[0];
    int secondTravel = trackNo[6] - trackNo[0] ;

    
    cout<<"Total No of movement that Read write head covered : "<<firstTRavel + secondTravel<<endl;
    cout<<firstTRavel<<endl;
    cout<<secondTravel<<endl;
}
