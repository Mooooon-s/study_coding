#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    ll arr[n];

    ll MAX=0,MIN=1234567890;
    
    for(int i=0;i<n;i++){
        cin >> arr[i];
        MAX = max(MAX,arr[i]);
        MIN = min(MIN,arr[i]);
    }

    ll a = MIN;
    ll b = MAX*m;

    ll r=0;
    while(a<=b){
        ll mid = (a+b)/2;

        ll cnt=0;
        for(int i=0;i<n;i++){
            cnt += (mid/arr[i]);
            if(cnt>=m) break;
        }

        if(cnt >=m){
            r=mid;
            b = mid -1;
        }
        else{
            a = mid +1;
        }
    }

    cout << r;
    
    

    return 0;
}