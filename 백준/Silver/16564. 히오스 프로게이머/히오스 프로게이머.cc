#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n , k;
    cin >> n >> k;
    ll arr[n];
    ll MAX=0,MIN=1000000000;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        MAX = max(MAX,arr[i]);
        MIN = min(MIN,arr[i]);
    }

    //cout << MAX+k << ' ' << MIN << "\n\n";

    ll a = MIN;
    ll b= MAX+k;

    ll r=0;
    while(a<=b){
        ll tmpK =k;
        ll T =b;

        //cout << "a b : " << a << " " << b << "\n";
        ll mid = (a+b)/2;

        //cout << "mid : " << mid << '\n';
        for(int i=0;i<n;i++){
            if(arr[i] >= mid ){
                //cout << arr[i] << ' ';
              continue;  
            } 
            ll x = mid-arr[i];
            ll y=b;

            if(x <= tmpK){
                y= arr[i] + x;
                //cout << y << '\n';
                tmpK-=x;
                T = min(T,y);
            }
            else{
                y = arr[i] + tmpK;
                //y = arr[i];
                //cout << y << '\n';
                tmpK=0;
                T = min(T,y);
            }
        }

        //cout << '\n';

        //cout << "mid: " << mid << " T: " << T << "\n\n";

        if(T<mid){
            b = mid-1;
        }
        else{
            r = max(r,mid);
            a = mid+1;
        }
    }
    
    cout << r;

    return 0;
}