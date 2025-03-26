#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int arr[m];

    for(int i=0;i<m;i++){
        cin >> arr[i];
    }

    int a =1;
    int b = n;

    int r= 0;
    while(a<=b){
        int mid = (a+b)/2;

        bool flag = true;
        if(arr[0]-mid > 0 ){
            a= mid+1;
            continue;
        }

        
        int l = arr[0] - mid;
        int h = arr[0] +mid;
        for(int i=1;i<m;i++){
            if(h >= arr[i]-mid){
                h = arr[i]+mid;
            }
            else{
                flag = false;
                break;
            }
        }

        if(h < n || !flag){
            a = mid+1;
        }
        else{
            r = mid;
            b = mid -1;
        }

    }

    cout << r;

    return 0;
}