#include <bits/stdc++.h>
using namespace std;

int main()
{
    int memoryArr[5] = {100, 500, 200, 300, 600};
    int processArr[4] = {212, 417, 112, 100};
    int fragmentedArr[5] = {0}; // in this array we will store the indixes of mem which are framgmented

    int flag;
    int ans[4];
    int ind = 0;
    for (int i = 0; i < 4; i++)
    {
        flag = 0;
        for (int j = 0; j < 5; j++)
        {

            if (processArr[i] <= memoryArr[j])  
            {
                memoryArr[j] = memoryArr[j] - processArr[i];
                fragmentedArr[j] = 1;
                ans[ind++] = j;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            int sum = 0;
            for (int m = 0; m < 5; m++)
            {
                if (fragmentedArr[m] == 1)
                {
                    sum += memoryArr[m]; // adding fragments
                }
            }
            // cout<<sum<<endl;
            if (sum >= processArr[i])
            {
                cout << "used fragmented block" << endl;
                
                        // now removeing  fragments to allocate memory to process

                        while (processArr[i] != 0)
                        {
                            for (int m = 0; m < 5; m++)
                            {
                                if (processArr[i] <= memoryArr[m] && fragmentedArr[m] == 1)
                                {
                                    processArr[i] = 0;
                                    memoryArr[m] = memoryArr[m] - processArr[i];  
                                    cout << "for process " << i << " using fragments " << m << "  "<<endl;;
                                    if(processArr[i] == 0) break;
                                }
                                else if(fragmentedArr[m] == 1)
                                {
                                    processArr[i] = processArr[i] - memoryArr[m];
                                    memoryArr[m] = 0;
                                    cout << "for process " << i << " using fragments " << m << "  "<<endl;
                                    if(processArr[i] == 0) break;
                                }
                            }
                        }
                   
            }else{
                cout<<"we cant allocate the memory to the process"<<i<<"th"<<endl;
            }
        }
    }

    cout << " zero based indexing" << endl;
    for (int i = 0; i < 4; i++)
    {
        if (ans[i] < 5)
            cout <<"The Proces " <<i<<"th  : " << ans[i] << "th block"<<endl;
    }

}