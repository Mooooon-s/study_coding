#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n,high,less;
    cin >> n >> high >> less;
    
    int* score= new int[n];
    for(int i=0;i<n;i++){
        cin >> score[i];
    }

    int rank=1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(score[i]==high){
            rank=rank;
        }
        else if(score[i]> high){
            rank+=1;
        }
        else break;
        cnt++;
    }

    if(cnt==less) rank=-1;
    if(n==0) rank=1;

    cout << rank;

    
    return 0;
}