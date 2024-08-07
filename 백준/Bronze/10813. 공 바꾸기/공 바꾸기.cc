#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int arr[MAX];

int main(){
    int n , m;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        arr[i]=i;
    }

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        int tmp = arr[a];
        arr[a]= arr[b];
        arr[b] =tmp;
    }

    for(int i=1;i<=n;i++){
        cout << arr[i] << ' ';
    }
    
    return 0;
}