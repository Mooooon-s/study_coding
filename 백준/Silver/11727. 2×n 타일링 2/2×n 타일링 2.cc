#include <bits/stdc++.h>

using namespace std;

int dp[1001];

int main(void){
    int n;
    cin >>n;
    
    dp[1]=1;
    dp[2]=3;
    dp[3]=5;
    for(int i=4;i<=n;i++){
        if(i%2==0)
            dp[i]=(2*dp[i-1]+1)%10007;
        else
            dp[i]=(2*dp[i-1]-1)%10007;
    }

    cout << dp[n];
    
    return 0;
}