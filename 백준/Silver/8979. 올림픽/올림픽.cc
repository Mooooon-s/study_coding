#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int k;
    cin >> n >> k;

    int glod[1001];
    int silver[1001];
    int bronze[1001];

    map<int , int> m;
    for(int i=0;i<n;i++){
        int idx;
        cin >> idx;
        cin >> glod[idx] >> silver[idx] >> bronze[idx];
    }

    int result=1;

    for(int i=0;i<n;i++){
        if(glod[i] > glod[k]){
            result++;
        }
        else if(glod[i]==glod[k]){
            if(silver[i]>silver[k]){
                result++;
            }
            else if(silver[i]==silver[k]){
                if(bronze[i]>bronze[k]){
                    result++;
                }
            }
        }
    }

    cout << result;
    
    return 0;
}