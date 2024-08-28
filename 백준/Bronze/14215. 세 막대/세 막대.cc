#include <bits/stdc++.h>

using namespace std;

int arr[3];

int main(){
    cin >> arr[0] >> arr[1] >> arr[2];

    sort(arr,arr+3);

    if(arr[2] < arr[0] + arr[1])
        cout << arr[2] + arr[0] + arr[1];
    else{
        arr[2] = arr[0] + arr[1] -1;
        cout << arr[0] + arr[1] + arr[2];
    }
    
    return 0;
}