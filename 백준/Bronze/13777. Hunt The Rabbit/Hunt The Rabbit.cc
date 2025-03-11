#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    while(1){
        cin >> n;
        if(n==0) break;

        int MIN=1;
        int MAX=50;

        while(MIN<=MAX){
            int mid = (MIN+MAX) /2;
            cout << mid << ' ';
            if(mid==n){
                break;
            }
            if(mid < n) MIN = mid +1;
            else MAX = mid -1;
        }
        cout << '\n';
    }
    

    return 0;
}