#include <bits/stdc++.h>

using namespace std;

int main(){
    int d;
    cin >>d;

    int cnt=0;
    for(int i=0;i<5;i++){
        int c;
        cin >>c;
        if(c==d)
            cnt++;
    }

    cout << cnt;
    
    return 0;
}