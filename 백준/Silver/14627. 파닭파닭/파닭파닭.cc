#include <bits/stdc++.h>

using namespace std;

bool vaild(long long mid);

long long s,c;
long long* L;



int main(){
    cin >> s>> c;
    L = new long long[s];
    for(int i=0;i<s;i++){
        cin >> L[i];
    }

    sort(L,L+s);

    long long a=1;
    long long b = L[s-1];

    long long r=0;
    while(a<=b){
        long long mid = (a+b)/2;

        if(vaild(mid)){
            r=mid;
            a=mid+1;
        }
        else{
            b= mid-1;
        }
        
    }

    //cout << r <<'\n';

    long long ans=0;
    for(int i=0;i<s;i++){
        ans+=L[i];
    }

    ans-=(c*r);

    cout << ans;
    

    return 0;
}

bool vaild(long long mid){
    long long cnt=0;
    for(int i=0;i<s;i++){
        cnt+=L[i]/mid;
    }

    if(cnt >=c){
        return true;
    }
    else return false;
}