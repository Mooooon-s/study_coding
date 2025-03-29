#include <bits/stdc++.h>

using namespace std;

int n;
long long r=0;
vector<long long> v;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    long long arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    int mid , a ,b , idx;

    for(int i=0;i<n-1;i++){
        a= i;
        b = n-1;
        idx = i;
        while(a<=b){
            mid = (a+b)/2;
            if(arr[i]>=0.9*arr[mid]){
                idx = max(mid,idx);
                a = mid +1;
            }
            else{
                b = mid -1;
            }
        }

        r += idx - i;
    }

    cout << r;
    
    return 0;
}