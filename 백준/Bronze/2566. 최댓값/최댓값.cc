#include <bits/stdc++.h>

using namespace std;

int board[9][9];

int mx =-1;
int x,y;

int main(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> board[i][j];
            if(mx < board[i][j])
            {
                mx = board[i][j];
                x = i+1;
                y = j+1;
            }
        }
    }

    cout << mx << '\n' << x << ' ' << y;
    return 0;
}