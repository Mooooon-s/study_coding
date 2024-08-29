#include <bits/stdc++.h>

using namespace std;

int arr[5];

int main(){
    for(int i=0;i<5;i++){
        cin >> arr[i];
    }

    sort(arr,arr+5);

    int result=0;
    for(int i=0;i<5;i++){
        result+=arr[i];
    }

    cout << result/5 << '\n' << arr[2];
    
    return 0;
}