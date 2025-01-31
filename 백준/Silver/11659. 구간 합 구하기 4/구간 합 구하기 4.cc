#include <bits/stdc++.h>

using namespace std;


int vec[100001];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;

    cin >> n >> m;

    
    vec[0]=0;
    for(int i=1;i<=n;i++){
       cin >> vec[i];
       vec[i]+=vec[i-1];
    }

    // for(int i=1;i<=n;i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';

    int a,b; 
    for(int i=0;i<m;i++){
        cin >> a >>b;
        cout << vec[b]-vec[a-1] << '\n';
    }

    return 0;
}