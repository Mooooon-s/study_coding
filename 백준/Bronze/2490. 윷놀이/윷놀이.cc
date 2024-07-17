#include <bits/stdc++.h>

using namespace std;

int arr[4];

int main(void){
    for(int j=0;j<3;j++){
        int cnt =0;
        for(int i=0;i<4;i++){
            cin >> arr[i];
            if(arr[i]==0)
                cnt++;
        }
        switch (cnt) {
            case 0:
                cout << "E\n";
                break;
            case 1:
                cout << "A\n";
                break;
            case 2:
                cout << "B\n";
                break;
            case 3:
                cout << "C\n";
                break;
            case 4:
                cout << "D\n";       
                break;
        }
    }
    
    return 0;
}