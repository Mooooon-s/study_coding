#include <bits/stdc++.h>

using namespace std;

int main(void){
    int mx=0;
    int now=0;

    vector<int> station;
    for(int i=1;i<=10;i++){
        int n,m;
        cin >> n >> m;
        now-=n;
        now+=m;

        station.push_back(now);
    }
    
    for(int i=0;i<station.size();i++){
        mx = max(mx,station[i]);
    }
    cout << mx;
    return 0;
}