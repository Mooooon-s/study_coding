#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    long long int an=2;

    for(int i=0;i<n;i++){
        an = an + pow(2,i);
    }

    long long int tmp = pow(an,2);
    cout << tmp;
    
    return 0;
}