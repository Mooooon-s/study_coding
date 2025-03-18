#include<bits/stdc++.h>

using namespace std;

long long n,k,m;
long long* arr;
long long MAX;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    
    cin >> n >> k >> m;

    arr= new long long[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i] <= k || arr[i] == k*2) arr[i]=0;
        if(arr[i] < 2*k){
            arr[i]-=k;
        }
        else{
            arr[i]-=(2*k);
        }

        MAX = max(MAX,arr[i]);
    }

    long long r =-1;

    long long a =1;
    long long b=MAX;
    while(a<=b){
        long long mid = (a+b)/2;

        long long cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0) 
                cnt+=(arr[i]/mid);
        }

        if(cnt>=m){
            //cout << mid<<'\n';
            r=mid;
            a= mid+1;
        }
        else{
            b= mid-1;
        }
    }

    cout << r;

    return 0;
}