#include <bits/stdc++.h>

using namespace std;

#define MAX 101

bool board[MAX][MAX];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        for(int i=y;i<y+10;i++){
            for(int j=x;j<x+10;j++){
                board[i][j]=true;
            }
        }
    }

    int cnt =0;
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            if(board[i][j])
                cnt+=1;
        }
    }

    cout << cnt;

    return 0;
}