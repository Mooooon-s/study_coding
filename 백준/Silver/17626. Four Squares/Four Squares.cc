#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int dp[50005];
    cin >>n;

    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]+1;
        for(int j=1;j*j<=i;j++){
            dp[i]= min(dp[i],dp[i-(j*j)]+1);
        }
    }

    //cout << n;
    //for(int i=0;i<=n;i++){
    //    cout << dp[i] << '\n';
    //}

    cout << dp[n];

    return 0;
}