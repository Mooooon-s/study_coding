#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long q = sqrt(n);

    if(q*q < n){
        q+=1;
    }
    
    cout << q;

    return 0;
}