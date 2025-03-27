#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    
    long long n , m;
    cin >> n >> m;
    long long arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);



    for(int i=0;i<m;i++){
        
        long long a = 0;
        long long b = n;
        
        long long r =-1;
        long long tc=0;
        bool flag = false;
        
        cin >> tc;
        while(a<=b){
            long long mid = (a+b)/2;

            if(arr[mid]>= tc){
                if(arr[mid]==tc){
                    flag = true;
                }
                r= mid;
                b = mid -1;
            }
            else{
                a = mid +1;
            }
        }

        if(flag)
            cout << r;
        else
            cout << -1;

        cout << '\n';
    }

    return 0;
}