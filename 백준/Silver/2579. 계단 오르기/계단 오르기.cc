#include <bits/stdc++.h>

using namespace std;

#define MAX 301

int n;

int dp[MAX];
int stair[MAX];

void InputStair();

void CalcStair();

void InputStair(){
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> stair[i];
    }
}

void CalcStair(){
    dp[1] = stair[1];
    dp[2] = max(stair[2],stair[1]+stair[2]);
    dp[3] = max(stair[1]+stair[3],stair[2]+stair[3]);

    for(int i =4 ; i<=n;i++){
        dp[i] = max(dp[i-3]+stair[i-1]+stair[i],
            dp[i-2]+stair[i]);
    }

    cout << dp[n];
}

int main(){
    
    InputStair();
    CalcStair();
    
    return 0;
}