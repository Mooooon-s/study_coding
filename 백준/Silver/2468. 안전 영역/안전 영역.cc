#include <bits/stdc++.h>

using namespace std;

#define MAX 101

typedef pair<int,int> pii;

int board[MAX][MAX];
int smap[MAX][MAX];

vector<pii> adj[MAX][MAX];
queue<pii> q;

bool visited[MAX][MAX];
int dist[MAX][MAX];

int main(void){
    int n;
    cin >> n;

    int mx=0;
    int Max=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
            mx = max(mx,board[i][j]);
        }
    }

    for(int k=1;k<=mx;k++){

        while(!q.empty()) q.pop();
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                adj[i][j].clear();
                visited[i][j]=0;
            }
        }


        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(board[i][j]<k){
                    smap[i][j]=1;
                }
                else{
                    if(i-1>=1 && smap[i-1][j]==0){
                        adj[i][j].push_back({i-1,j});
                        adj[i-1][j].push_back({i,j});
                    }
                    if(j-1>=1 && smap[i][j-1]==0){
                        adj[i][j].push_back({i,j-1});
                        adj[i][j-1].push_back({i,j});
                    }
                }
            }
        }

        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=n;j++){
        //        cout << smap[i][j]<<' ';
        //    }
        //    cout << '\n';
        //}
        //cout << '\n';
        
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(smap[i][j]==0 && !visited[i][j]){
                    visited[i][j]=true;
                    cnt++;
                    q.push({i,j});
                }

                while(!q.empty()){
                    auto s = q.front(); q.pop();
                    for(auto u : adj[s.first][s.second]){
                        int a=u.first;
                        int b= u.second;
                        if(visited[a][b])continue;
                        visited[a][b]=true;
                        q.push({a,b});
                    }
                }
            }
        }
        //cout << cnt << '\n';
        Max = max(Max,cnt);
    }
    
    cout << Max;
    
    return 0;
}