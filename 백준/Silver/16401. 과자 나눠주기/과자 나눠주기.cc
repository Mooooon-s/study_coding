#include <bits/stdc++.h>

using namespace std;

int main(){
    int m , n;
    cin >> m >> n;
    int* cookie = new int[n];
    for(int i=0;i<n;i++){
        cin >> cookie[i];
    }

    sort(cookie,cookie+n);

    int a = 1;
    int b = cookie[n-1];

    int r=0;
    while(a<=b){
        int cnt=0;
        int mid = (a+b)/2;

        for(int i=0;i<n;i++){
            cnt += cookie[i]/mid;
        }

        if(cnt < m){
            b =mid - 1;
        }
        else if(cnt >= m){
            r= mid;
            a= mid + 1;
        }
    }
    cout << r;

    return 0;
}