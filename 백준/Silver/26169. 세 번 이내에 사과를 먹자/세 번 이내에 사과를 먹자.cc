#include <bits/stdc++.h>

using namespace std;

#define MAX 5

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];

int board[MAX][MAX];

bool visited[MAX][MAX];

bool flag=false;

void dfs(pii p,int cnt,int level){
    if(level>3 || flag )return;
    if(visited[p.first][p.second])return;
    visited[p.first][p.second]=true;
    if(board[p.first][p.second]==1) cnt++;
    if(cnt>=2){ flag=true; return; }

    // cout << cnt;
    // cout << '\n';
    
    // for(int i=0;i<MAX;i++){
    //     for(int j=0;j<MAX;j++){
    //         cout << visited[i][j];
    //     }
    //     cout << '\n';
    // }
    
    
    for(auto u : adj[p.first][p.second]){
        dfs(u,cnt,level+1);
    }
    visited[p.first][p.second]=false;
}

int main(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            cin >> board[i][j];
            if(board[i][j]!=-1){
                if(i-1>=0 && board[i-1][j]!=-1){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }

                if(j-1>=0 && board[i][j-1]!=-1){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                }
            }
        }
    }

    pii a;
    cin >> a.first >> a.second;

    dfs(a,0,0);

    if(flag) cout << 1;
    else cout << 0;

    // cout << '\n';
    // for(int i=0;i<MAX;i++){
    //     for(int j=0;j<MAX;j++){
    //         cout << board[i][j];
    //     }
    //     cout << '\n';
    // }
    
    return 0;
}