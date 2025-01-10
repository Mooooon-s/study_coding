#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> AB;

#define f first
#define s second


int k;
vector<AB> dp;

int main(){
    cin >> k;

    dp.push_back({1,0});
    dp.push_back({0,1});
    dp.push_back({1,1});

    for(int i=3;i<=k;i++){
        int a = dp[i-1].second;
        int b = dp[i-1].first+dp[i-1].second;
        auto ab = AB({a,b});
        dp.push_back(ab);
    }

    cout << dp[k].first << ' ' << dp[k].second;
    
    return 0;
}