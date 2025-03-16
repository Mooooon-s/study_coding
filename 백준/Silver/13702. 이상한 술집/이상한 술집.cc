#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    long long* bottle = new long long[n];
    for(int i=0;i<n;i++){
        cin >> bottle[i];
    }

    sort(bottle,bottle+n);

    long long a= 1;
    long long b= bottle[n-1];

    long long r=0;
    while(a<=b){
        long long mid = (a+b)/2;
        
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=bottle[i]/mid;
        }

        if(cnt >=k)
        {
            r=mid;
            a=mid+1;
        }
        else b=mid-1;
    }

    cout << r;

    return 0;
}