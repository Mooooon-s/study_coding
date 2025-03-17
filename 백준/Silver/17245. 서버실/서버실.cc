#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
ll arr[1000][1000];
ll totalCom=0;
ll halfCom=0;

bool vaild(long long mid){
    long long cnt =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]<=mid) cnt+=arr[i][j];
            else cnt+=mid;
        }
    }

    if(cnt >=halfCom) return true;
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
            totalCom+=arr[i][j];
        }
    }

    halfCom = round((double)totalCom/2);

    ll a=0;
    ll b=10000000;

    ll r=0;
    
    while(a<=b){
        ll mid = (a+b)/2;

        if(vaild(mid)){
            r = mid;
            b = mid-1;
        }
        else a = mid +1;
    }

    cout << r;

    return 0;
}