#include <bits/stdc++.h>
#define MAX 21

using namespace std;

int arr[MAX];

int main(){
    int p;
    cin >> p;

    for(int i=0;i<p;i++){
        int T;
        cin>> T;

        // get height of student
        for(int i=0;i<20;i++){
            cin >> arr[i];
        }

        int cnt =0;
        for(int i=0;i<20;i++){
            for(int j=0;j<i;j++){
                if(arr[j] > arr[i] ){
                    int temp = arr[i];
                    for(int k=i;k>j;k--){
                        arr[k] = arr[k-1];
                        cnt++;
                    }
                    arr[j]=temp;
                    break;
                }
            }
            
        }

        cout << T << ' ' << cnt << '\n';


        
    }

    return 0;
}