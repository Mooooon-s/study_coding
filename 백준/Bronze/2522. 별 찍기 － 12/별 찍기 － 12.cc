#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    bool flag=true;

    int cnt=n;
    for(int i=1;i<=2*n-1;i++){
        if(flag){
            for(int j=n-i;j>0;j--){
                cout <<' ';
            }
            for(int j=0;j<i;j++){
                cout << '*';
            }
            cout << '\n';            
        }
        else{
            for(int j=i-n;j>0;j--){
                cout << ' ';
            }
            for(int j=cnt-(i-n);j>0;j--){
                cout << '*';
            }
            cout << '\n';
        }

        if(i==n)
            flag=false;
    }
    
    return 0;
}