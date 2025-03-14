#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    int* arrA = new int[n];
    int* arrB = new int[m];
    
    for(int i=0;i<n;i++){
        cin >> arrA[i];
    }
    
    for(int i=0;i<m;i++){
        cin >> arrB[i];
    }

    sort(arrA,arrA+n);
    sort(arrB,arrB+m);

    // for(int i=0;i<n;i++){
    //     cout << arrA[i] << ' ';
    // }
    // cout << '\n';
    // for(int i=0;i<m;i++){
    //     cout << arrB[i] << ' ';
    // }
    // cout << '\n';

    vector<int> v;

    for(int i=0;i<n;i++){
        bool flag=false;
        int a = 0;
        int b = m-1;

        while(a<=b){
            int mid = (a+b)/2;
            if(arrB[mid]==arrA[i]){
                flag=true;
                break;
            }
            if(arrA[i]> arrB[mid]) a = mid+1;
            else b = mid-1;
        }

        if(!flag){
            v.push_back(arrA[i]);
        }
    }

    cout << v.size() << '\n';
    for(auto vec : v){
        cout << vec << ' ';
    }

    return 0;
}