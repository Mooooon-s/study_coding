#include <bits/stdc++.h>

using namespace std;

#define MAX 10001

int arr[MAX];

int main(){
    int n,k;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    sort(arr,arr+n);

    // for(int i=0;i<n;i++){
    //     cout << arr[i] <<' ';
    // }

    cout << arr[n-k];
        
    return 0;
}