#include <bits/stdc++.h>

using namespace std;

#define MAX 101

struct piii {
    int a;
    int b;
    int c;
};

vector<piii> adj[MAX][MAX][MAX];
queue<piii> q;

bool visited[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];

int board[MAX][MAX][MAX];

int main(void){
    int m,n,h;
    cin>>n>>m>>h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                board[i][j][k]=-1;
                cin >> board[i][j][k];
                if(board[i][j][k]==-1)
                    dist[i][j][k]=-1;
                if(board[i][j][k]==1){
                    visited[i][j][k]=true;
                    dist[i][j][k]=1;
                    piii p;
                    p.a=i;
                    p.b=j;
                    p.c=k;
                    q.push(p);
                    if(i-1 >=1 && board[i-1][j][k]==0){
                        piii p;
                        p.a = i-1;
                        p.b = j;
                        p.c = k;
                        adj[i][j][k].push_back(p);
                    }

                    if(j-1 >=1 && board[i][j-1][k]==0){
                        piii p;
                        p.a = i;
                        p.b = j-1;
                        p.c = k;
                        adj[i][j][k].push_back(p);
                    }

                    if(k-1 >=1 && board[i][j][k-1]==0){
                        piii p;
                        p.a = i;
                        p.b = j;
                        p.c = k-1;
                        adj[i][j][k].push_back(p);
                    }
                }

                if(board[i][j][k]==0){
                    if(i-1 >=1 && board[i-1][j][k]==1){
                        piii p;
                        p.a = i;
                        p.b = j;
                        p.c = k;
                        adj[i-1][j][k].push_back(p);
                    }

                    if(j-1 >=1 && board[i][j-1][k]==1){
                        piii p;
                        p.a = i;
                        p.b = j;
                        p.c = k;
                        adj[i][j-1][k].push_back(p);
                    }

                    if(k-1 >=1 && board[i][j][k-1]==1){
                        piii p;
                        p.a = i;
                        p.b = j;
                        p.c = k;
                        adj[i][j][k-1].push_back(p);
                    }

                    if(i-1 >=1 && board[i-1][j][k]==0){
                        piii p1,p2;
                        p1.a = i-1;
                        p1.b = j;
                        p1.c = k;
                        adj[i][j][k].push_back(p1);
                        p2.a = i;
                        p2.b = j;
                        p2.c = k;
                        adj[i-1][j][k].push_back(p2);
                    }

                    if(j-1 >=1 && board[i][j-1][k]==0){
                        piii p1,p2;
                        p1.a = i;
                        p1.b = j-1;
                        p1.c = k;
                        adj[i][j][k].push_back(p1);
                        p2.a = i;
                        p2.b = j;
                        p2.c = k;
                        adj[i][j-1][k].push_back(p2);
                    }

                    if(k-1 >=1 && board[i][j][k-1]==0){
                        piii p1,p2;
                        p1.a = i;
                        p1.b = j;
                        p1.c = k-1;
                        adj[i][j][k].push_back(p1);
                        p2.a = i;
                        p2.b = j;
                        p2.c = k;
                        adj[i][j][k-1].push_back(p2);
                    }
                }
            }
        }
    }

    int mx=1;
    
    while(!q.empty()){
        auto s = q.front(); q.pop();
        for(auto u : adj[s.a][s.b][s.c] ){
            int a= u.a;
            int b= u.b;
            int c= u.c;
            if(visited[a][b][c])continue;
            visited[a][b][c]=true;
            dist[a][b][c] = dist[s.a][s.b][s.c]+1;
            //cout << dist[s.a][s.b][s.c] << '\n';
            piii p;
            p.a = a;
            p.b = b;
            p.c = c;
            q.push(p);
        }
    }
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=n;k++){
                //cout << dist[i][j][k] << ' ';
                //max(mx,dist[i][j][k]);
                if(mx < dist[i][j][k])
                    mx=dist[i][j][k];
                if(dist[i][j][k]==0){
                    cout << -1;
                    return 0;
                }
            }
            //cout << '\n';
        }
        //cout << '\n';
    }

    cout << mx-1;
    return 0;
}