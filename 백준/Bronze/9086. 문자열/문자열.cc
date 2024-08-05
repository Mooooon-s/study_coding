#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string n;
        cin >> n;
        cout << n[0] << n[n.size()-1] << '\n';
    }
    
    return 0;
}