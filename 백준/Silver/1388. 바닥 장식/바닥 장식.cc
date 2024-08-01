#include <bits/stdc++.h>

using namespace std;

#define MAX 51
typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];

bool visited[MAX][MAX];

char board[MAX][MAX];

void dfs(int a, int b){
    if(visited[a][b]) return;
    visited[a][b]=true;
    for(auto u : adj[a][b]){
        dfs(u.first,u.second);
    }
}

int main(void){
    int x , y;
    cin >> y >> x;
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            cin >> board[i][j];
            if(board[i][j]=='-'){
                if(j-1 >0 && board[i][j-1]=='-'){
                    adj[i][j-1].push_back({i,j});
                }
            }

            if(board[i][j]=='|'){
                if(i-1 > 0 && board[i-1][j]=='|'){
                    adj[i-1][j].push_back({i,j});
                }
            }
        }
    }

    int cnt=0;
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            if(!visited[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt;
    
    return 0;
}