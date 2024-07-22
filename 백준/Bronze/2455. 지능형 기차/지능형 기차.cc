#include <bits/stdc++.h>

using namespace std;

int station[5];

int Max =-1;

int main(){
    station[0]=0;
    for(int i=1;i<=4;i++){
        int in,out;
        cin >> out >> in;

        station[i]=station[i-1]-out;
        
        station[i]+=in;
        
        if(station[i]>=10000)
            station[i]=10000;

        if(Max<station[i])
            Max=station[i];
    }
    cout << Max;
    return 0;
}