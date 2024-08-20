#include <bits/stdc++.h>

using namespace std;

int money[4];

int bucket[4] = { 25, 10 , 5, 1 };

int main(){
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n;
        cin >> n;

        
        for(int j=0;j<4;j++){
            money[j] = (n / bucket[j]);
            n%=bucket[j];
        }

        for(int j=0;j<4;j++){
            cout << money[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}