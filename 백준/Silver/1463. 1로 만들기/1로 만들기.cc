#include <bits/stdc++.h>

using namespace std;

#define MAX 10000001

int n;
int dp[MAX];

int DP(int n);

int main(){
    cin >> n;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;

    dp[n] = DP(n);

    cout << dp[n];
    
    return 0;
}

int DP(int a){
    if(n==1)
        return 0;
    
    if(dp[a]>0)
        return dp[a];

    dp[a] = DP(a-1)+1;
        
    if(a%2==0)
        dp[a] = min(dp[a],DP(a/2)+1);
    if(a%3==0)
        dp[a] = min(dp[a],DP(a/3)+1);

    return dp[a];
}