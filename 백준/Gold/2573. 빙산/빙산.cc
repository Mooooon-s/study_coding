#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define MAX 301

vector<pii> adj[MAX][MAX];
int icedist[MAX][MAX];
int dist[MAX][MAX];
int board[MAX][MAX];

bool visited[MAX][MAX];

queue<pii> q;

void updateData(int n,int m){
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            icedist[i][j]=0;
            visited[i][j]=false;
            dist[i][j]=0;
            adj[i][j].clear();
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(board[i][j]==0){
                if(i-1>=1 && board[i-1][j]!=0){
                    icedist[i-1][j]++;
                }
        
                if(j-1 >=1 && board[i][j-1]!=0){
                    icedist[i][j-1]++;
                }
                icedist[i][j]=0;
            }
        
            if(board[i][j]!=0){
                if(i-1>=1 && board[i-1][j]!=0){
                    adj[i-1][j].push_back({i,j});
                    adj[i][j].push_back({i-1,j});
                }
        
                if(j-1 >=1 && board[i][j-1]!=0){
                    adj[i][j-1].push_back({i,j});
                    adj[i][j].push_back({i,j-1});
                }
        
                
                if(i-1>=1 && board[i-1][j]==0){
                    icedist[i][j]++;
                }
        
                if(j-1 >=1 && board[i][j-1]==0){
                    icedist[i][j]++;
                }
            }
        }
    }
}

void meltdown(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(board[i][j]!=0){
                board[i][j]-=icedist[i][j];
                if(board[i][j]<=0)
                    board[i][j]=0;
            }
        }
    }
}

int main(void){
    int n,m;
    cin >> n>>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> board[i][j];
        }
    }
    
    updateData(n,m);
    int year=1;
    while(1){
        meltdown(n,m);
        updateData(n,m);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(board[i][j]!=0 && !visited[i][j]){
                    visited[i][j]=true;
                    dist[i][j]=1;
                    q.push({i,j});
                    cnt++;
                    int ice=1;
                    while(!q.empty()){
                        auto s = q.front(); q.pop();
                        for(auto s : adj[s.first][s.second]){
                            int a = s.first;
                            int b = s.second;
                            if(visited[a][b])continue;
                            visited[a][b]=true;
                            dist[a][b]=++ice;
                            q.push({a,b});
                        }
                    }
                }
            }
        }

        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=m;j++){
        //         cout << board[i][j];
        //     }
        //     cout<< '\n';
        // }
        // cout<< '\n';
        
        if(cnt > 1){
            cout<< year;
            break;
        }else if (cnt==0){
            cout<< 0;
            break;
        }
        
        year++;
    }
    
    return 0;
}