#include <bits/stdc++.h>

using namespace std;

#define MAX 301

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
queue<pii> q;

int board[MAX][MAX];

bool visited[MAX][MAX];

void printvis(int m,int n){
    cout << '\n';
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void printbd(int m,int n){
    cout << '\n';
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}


int main(void){
    int n , m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
        }
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(board[i][j]==1){
                if(i+1<=m && board[i+1][j]==1){
                    adj[i][j].push_back({i+1,j});
                }
                if(j+1<=n && board[i][j+1]==1){
                    adj[i][j].push_back({i,j+1});
                }
            }
        }
    }

    q.push({1,1});
    visited[1][1]=true;

    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(s.first == m && s.second == n){
            cout << "Yes";
            // printvis(m,n);
            return 0;
        }
        for(auto u : adj[s.first][s.second]){
            int a = u.first;
            int b = u.second;
            if(a<m && b<n && visited[a][b])continue;
            q.push({a,b});
            visited[a][b]=true;
        }
    }

    cout << "No";
    // printbd(m,n);
    // printvis(m,n);
    return 0;
}