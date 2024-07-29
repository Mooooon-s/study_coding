#include <bits/stdc++.h>

using namespace std;

#define MAX 4

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];

queue<pii> q;

bool visited[MAX][MAX];

int board[MAX][MAX];

int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a = board[i][j];
            if(a==-1)continue;
            if(i+a<=n){
                adj[i][j].push_back({i+a,j});
            }

            if(j+a<=n){
                adj[i][j].push_back({i,j+a});
            }
        }
    }


    q.push({1,1});
    visited[1][1]=true;

    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(board[s.first][s.second]==-1){
            cout << "HaruHaru";
            return 0;
        }
        for(auto u : adj[s.first][s.second]){
            int a = u.first;
            int b = u.second;
            if(visited[a][b])continue;
            q.push({a,b});
            visited[a][b]=true;
        }
    }

    cout << "Hing";

    return 0;
}