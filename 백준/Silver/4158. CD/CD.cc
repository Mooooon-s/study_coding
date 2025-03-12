#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,m;

    while(1){
        //get testcase
        int cnt=0;
        cin >> n >> m;
        if(n==0 && m==0) break;

        //get first list
        int* n_arr = new int[n];
        for(int i=0;i<n;i++){
            cin >> n_arr[i];
        }
        

        //find second list numbers in first list
        for(int i=0;i<m;i++){
            int num;
            cin >> num;
    
            int a=0;
            int b=n-1;
            while(a<=b){
                int mid = (a+b)/2;
                if(n_arr[mid] == num){
                    cnt++;
                    break;
                }
                if(n_arr[mid] < num) a = mid +1;
                else b = mid -1;
            }
        }
    
        cout << cnt<<'\n';
    }

    return 0;
}