#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=0;j<n;j++){
                cout << '*' << ' ';
            }
            cout << "\n";
        }
        else
        {
            for(int j=0;j<n;j++){
                cout << ' ' << '*';
            }
            cout << "\n";
        }
    }
    
    return 0;
}