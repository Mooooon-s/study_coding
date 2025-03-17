#include <bits/stdc++.h>

using namespace std;


long long n , m;
long long bal;
long long* blow;

bool vaild(long long mid){
    long long cnt =0;
    for(int i=0;i<n;i++){
        cnt+=(mid/blow[i]);
    }

    if(cnt >=m) return true;
    return false;
}

int main(){
    cin.tie(0);
    
    cin >> n >> m;
    blow = new long long[n];

    for(int i=0;i<n;i++){
        cin >> blow[i];
    }

    sort(blow, blow+n);

    long long a=1;
    long long b =blow[n-1]*m+1;
    long long r =-1;
    
    while(a<=b){
        long long mid = (a+b)/2;

        if(vaild(mid)){
            r=mid;
            b=mid-1;
        }
        else{
            a=mid+1;
        }
    }

    cout << r;
    
    return 0;
}
