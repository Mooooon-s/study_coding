#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define MAX 1001


struct iii{
    int a,b,c;
};

vector<pii> adj[MAX][MAX];
queue<iii> q;

bool visited[MAX][MAX][3];
int dist[MAX][MAX][3];

int board[MAX][MAX];

int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        for(int j=1;j<=m;j++){
            board[i][j] = s[j-1]-'0';
            if(i-1>=1){
                adj[i][j].push_back({i-1,j});
                adj[i-1][j].push_back({i,j});
            }
            if(j-1>=1){
                adj[i][j].push_back({i,j-1});
                adj[i][j-1].push_back({i,j});
            }
        }
    }

    iii p;
    p.a=1; p.b=1; p.c=0;
    visited[1][1][0]=true;
    dist[1][1][0]=1;
    q.push(p);

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << board[i][j];
    //     }
    //     cout<<'\n';
    // }

    int cnt=0;

    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(s.a==n && s.b==m){
            cout << dist[s.a][s.b][s.c];
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=m;j++){
            //         cout << dist[i][j][0];
            //     }
            //     cout<<'\n';
            // }
            // cout<< '\n';
        
            // for(int i=1;i<=n;i++){
            //     for(int j=1;j<=m;j++){
            //         cout << dist[i][j][1];
            //     }
            //     cout<<'\n';
            // }
            return 0;
        }
        for(auto u : adj[s.a][s.b]){
            int a = u.first;
            int b = u.second;
            int c = s.c;
            // cout << ++cnt << ": " << a << ' ' << b << ' ' << c << '\n';
            if(visited[a][b][c])continue;
            if(board[a][b]==1 && s.c==0){
                iii p;
                p.a = a; p.b = b; p.c =1;
                q.push(p);
                visited[a][b][p.c]=true;
                dist[a][b][p.c]=dist[s.a][s.b][s.c]+1;
            }
            if(board[a][b]==0){
                iii p;
                p.a = a; p.b = b; p.c = c;
                q.push(p);
                visited[a][b][p.c]=true;
                dist[a][b][p.c]=dist[s.a][s.b][s.c]+1;
            }
        }
    }
    
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << dist[i][j][0];
    //     }
    //     cout<<'\n';
    // }
    // cout<< '\n';

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << dist[i][j][1];
    //     }
    //     cout<<'\n';
    // }
    cout << -1;
    
    return 0;
}