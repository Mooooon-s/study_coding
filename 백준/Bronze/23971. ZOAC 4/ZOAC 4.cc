#include <bits/stdc++.h>

using namespace std;

int main(){
    int h,w,n,m;
    cin >> h>>w>>n>>m;

    int cnt=0;
    for(int i=1;i<=h;i+=(n+1)){
        for(int j=1;j<=w;j+=(m+1)){
            if(i<=h && j <=w){
                //cout << i <<','<<j<<'\n';
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}