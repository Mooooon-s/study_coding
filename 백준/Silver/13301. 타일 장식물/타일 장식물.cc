#include <bits/stdc++.h>

using namespace std;

long long int dp[82];

int main(){
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    dp[4]=3;
    dp[5]=5;
    dp[6]=8;
    
    int n;
    cin >> n;

    for(int i=7;i<=n+1;i++){
        dp[i]= dp[i-1]+dp[i-2];
    }

    //cout << dp[n] << ' ' << dp[n+1] << '\n';

    cout << (2*dp[n+1])+(2*dp[n]);
    
    return 0;
}