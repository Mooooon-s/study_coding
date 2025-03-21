#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n,m;
    cin >> n >>m;
    ll arr[n];
    ll MAX=0;
    ll tmpS=0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        MAX= max(MAX,arr[i]);
        tmpS+=arr[i];
    }

    ll a=MAX;
    ll b=tmpS;

    ll r=tmpS;
    while(a<=b){
        ll mid = (a+b)/2;

        ll cnt=1;
        ll temp=mid;

        for(int i=0;i<n;i++){
            if(temp - arr[i] < 0){
                cnt++;
                temp=mid - arr[i];
            }
            else{
                temp-=arr[i];
            }
        }

        if(cnt <= m)
        {
            r=mid;
            b = mid -1;
        }
        else{
            a= mid+1;
        }
    }

    cout << r;

    return 0;
}