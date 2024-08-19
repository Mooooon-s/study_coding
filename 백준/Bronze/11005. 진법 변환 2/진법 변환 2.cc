#include <bits/stdc++.h>

using namespace std;

#define MAX 37

long long int n;

int b;

int arr[MAX];

int main(){
    cin >> n >> b;

    //나누어 떨어지지 않을 때 까지
    int i=0;
    while(n/b!=0){
        arr[i] = n%b;
        n/=b;
        i++;
    }

    arr[i] = n%b;
    i+=1;

    // cout << i << '\n';

    // for(int j=0;j<i;j++){
    //     cout << arr[j] << ' ';
    // }
    // cout << '\n';

    for(int j=i-1;j>=0;j--){
        if(arr[j]>9)
            cout << (char)((arr[j]-10) + 'A');
        else
            cout << arr[j];
    }
    
    return 0;
}