#include <bits/stdc++.h>

using namespace std;

int main(void){
    long a,b;
    while(1){   
        cin >> a >> b;
        if(a==0 && b==0){
            return 0;
        }
        if(a>b)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}