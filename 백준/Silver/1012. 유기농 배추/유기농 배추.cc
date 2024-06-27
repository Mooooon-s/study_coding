#include <bits/stdc++.h>

using namespace std;

#define MAX 51

typedef pair<int,int> pii;
vector<pii> adj[MAX][MAX];
queue<pii> q;

bool visited[MAX][MAX];
int dist[MAX][MAX];



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >>t;

    for(int i=0;i<t;i++){
        int ma[MAX][MAX];

        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                ma[i][j]=0;
                visited[i][j]=false;
                adj[i][j].clear();
            }
        }
        
        int n,m,c;
        cin >> m >> n >> c;
        for(int i=0; i<c; i++){
            int a,b;
            cin>> a >> b;
            ma[b][a]=1;
        }
    
        int cnt=0;
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ma[i][j]==1){
                    if(i-1>=0 && ma[i-1][j]==1){
                        adj[i][j].push_back({i-1,j});
                        adj[i-1][j].push_back({i,j});
                    }
                    if(j-1>=0 && ma[i][j-1]==1){
                        adj[i][j-1].push_back({i,j});
                        adj[i][j].push_back({i,j-1});
                    }
                }
            }
       }
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ma[i][j]==1 && !visited[i][j]){
                    visited[i][j]=true;
                    q.push({i,j});
                    cnt++;
                    while(!q.empty()){
                        auto s = q.front(); q.pop();
                        for(auto u : adj[s.first][s.second]){
                            int a = u.first;
                            int b = u.second;
                            if(visited[a][b])continue;
                            visited[a][b]=true;
                            q.push({a,b});
                       }
                    }
                }
            }
        }
        
        cout << cnt <<'\n';
        }

        return 0;
}