#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    cin.tie(0)->sync_with_stdio(false);

    ll n , m;
    cin >> n >> m;
    ll* arr = new ll[n];

    ll MAX = 0;
    ll a=-1,b=0;

    for(int i=0;i<n;i++){
        cin >> arr[i];
        MAX += arr[i];
        a=max(a,arr[i]);
    }

    b= MAX;

    while(a<=b){
        ll cnt=0;
        ll sum=0;
        
        ll mid = (a+b)/2;


        for(int i=0;i<n;i++){
            if(sum + arr[i] > mid){
                sum=0;
                cnt++;
            }
            sum+=arr[i];
        }

        if(sum!=0) cnt++;

        if(cnt <=m){
            b = mid -1;
        }
        else{
            a = mid +1;
        }
        
    }

    cout << a;

    return 0;
}