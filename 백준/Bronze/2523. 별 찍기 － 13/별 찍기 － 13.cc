#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    bool flag=true;
    int cnt=1;
    for(int i=0;i<2*n-1;i++){
        if(flag){
            for(int j=0;j<cnt;j++){
                cout << '*';
            }
            cnt++;
            cout <<'\n';
        }
        else{
            for(int j=cnt;j>0;j--){
                cout << '*';
            }
            cnt--;
            cout << '\n';
        }
        if(cnt==n)
            flag=!flag;
    }
    return 0;
}