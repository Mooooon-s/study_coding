#include <bits/stdc++.h>

using namespace std;

#define MAX 37

long long arr[MAX];

int main(){
    string n;
    int b;
    cin >> n >> b;

    for(int i=n.size()-1;i>=0;i--){
        int delta=0;
        if(n[i] >= 'A' && n[i] <='Z'){
            delta = n[i] - 'A';
            delta +=10;
        }

        else{
            delta = n[i] -'0';
        }

        arr[i] = pow ( b,(n.size()-1)-i ) * delta;
    }

    long long result=0;

    // for(int i=0;i<n.size();i++){
    //     cout << arr[i] << ' ';
    // }
    // cout <<'\n';

    for(int i=0;i<n.size();i++){
        result+=arr[i];
    }

    cout << result;
    
    return 0;
}