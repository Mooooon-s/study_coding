#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main(){
    int L;

    while(1){
        cin >> L;
        if(L==0) break;

        dp[1]=1;
        dp[2]=3;
        dp[3]=6;
        dp[4]=10;

        for(int i=5;i<=L;i++){
            dp[i]=dp[i-1]+i;
        }

        cout << dp[L] << '\n';
    }

    return 0;
}