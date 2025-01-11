#include <bits/stdc++.h>

using namespace std;

int st;
int** arr;
int* count;

int main(){
    cin >> st;
    int** arr = new int*[st];
    int* count = new int[st];
    for(int i=0;i<st;i++){
        arr[i] = new int[5];
    }

    vector<int> v[st];

    for(int i=0;i<st;i++){
        for(int j=0;j<5;j++){
            cin >> arr[i][j];
        }
    }

    for(int k=0;k<5;k++){
        for(int i=0;i<st;i++){
            for(int j=0;j<st;j++){
                if(i==j)
                    continue;
                if(arr[i][k]==arr[j][k]){
                    if(find(v[i].begin(),v[i].end(),j)==v[i].end()){
                        v[i].push_back(j);
                        count[i]++;
                    }
                }
            }
            
        }
    }

    int Max = -1;
    int t =0;

    for(int i=0;i<st;i++){
       // cout << count[i] << ' ';
        if(Max < count[i]){
            Max = count[i];
            t=i;
        }
    }

    cout<< t+1;
    
    return 0;
}