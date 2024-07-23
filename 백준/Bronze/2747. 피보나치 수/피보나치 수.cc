#include <bits/stdc++.h>

using namespace std;

vector<int> fi;

int main(void){

    fi.push_back(0);
    fi.push_back(1);

    int n;

    cin >> n;

    for(int i=2;i<=n;i++){
        fi.push_back(fi[i-2]+fi[i-1]);
    }
    
    cout << fi[n];
    
    return 0;
}