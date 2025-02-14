#include <bits/stdc++.h>

using namespace std;

long long int* dp;

int main(){
    dp= new long long int[101];
    int n;
    cin >> n;

    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    dp[5]=2;
    dp[6]=3;

    for(int i=0;i<n;i++){
        int a;
        cin >> a;

        if(a<=6)
            cout << dp[a]<<'\n';
        else{
            for(int i=7;i<=a;i++){
                dp[i]=dp[i-1]+dp[i-5];
                //cout << i << "= " << dp[i-1] << "+" << dp[i-5] << '=' << dp[i]<<'\n';
            }

            cout << dp[a] << '\n';
        }
    }
    
    return 0;
}