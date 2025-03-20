#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    ll arr[m]={0};

    ll h=-1;
    for(int i=0;i<m;i++){
        cin >> arr[i];
        h=max(h,arr[i]);
    }

    ll a=1;
    ll b=h;

    ll ans=h;
    while(a<=b){
        ll mid = (a+b)/2;

        int cnt=0;
        for(int i=0;i<m;i++){
            cnt+=(arr[i]/mid);
            if(arr[i]%mid!=0) cnt++;
        }

        if(cnt <= n){
            ans = mid;
            b= mid -1;
        }
        else{
            a = mid+1;
        }
    }

    cout << ans;
    
}