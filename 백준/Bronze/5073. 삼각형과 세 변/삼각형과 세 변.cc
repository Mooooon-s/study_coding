#include<bits/stdc++.h>

using namespace std;

int arr[3];

int main(){

    while(1){
        int a,b,c;
        cin >> arr[0] >> arr[1] >> arr[2];

        if(arr[0]+arr[1]+arr[2] == 0)
            break;

        sort(arr,arr+3);

        // for(int i=0;i<3;i++){
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';

        if(arr[2] >= arr[0] + arr[1])
            cout << "Invalid\n";
        else{
            if(arr[0]==arr[1] && arr[0] == arr[2])
                cout << "Equilateral\n";
            else if(arr[0] == arr[1] || arr[0] == arr[2]|| arr[1] == arr[2])
                cout << "Isosceles\n";
            else
                cout << "Scalene\n";
        }
        
    }

    

    
    return 0;
}