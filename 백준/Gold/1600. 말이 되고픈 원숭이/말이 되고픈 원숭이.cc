#include <bits/stdc++.h>

using namespace std;

#define MAX 201

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
vector<pii> hadj[MAX][MAX];

queue<pair<pii,int>> q;

bool visited[MAX][MAX][31];
int dist[MAX][MAX][31];

int board[MAX][MAX];

vector<int> mx;

int main(){
    int k,w,h;
    cin >> k >> w >> h;

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> board[i][j];
            if(board[i][j]==0){
                if(i-1>=1 && board[i-1][j]==0){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }

                if(j-1>=1 && board[i][j-1]==0){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                }
            }
        }
    }

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(board[i][j]==0){
                
                if(j+1 <= w && i-2 >=1 && board[i-2][j+1]==0){
                    hadj[i][j].push_back({i-2,j+1});
                    hadj[i-2][j+1].push_back({i,j});
                }
                
                if(j+2 <= w && i-1>=1 && board[i-1][j+2]==0 ){
                    hadj[i][j].push_back({i-1,j+2});
                    hadj[i-1][j+2].push_back({i,j});
                }
                
                if(j+2 <= w && i+1 <= h && board[i+1][j+2]==0){
                    hadj[i][j].push_back({i+1,j+2});
                    hadj[i+1][j+2].push_back({i,j});
                }
                
                if(j+1 <= w && i+2 <= h && board[i+2][j+1]==0){
                    hadj[i][j].push_back({i+2,j+1});
                    hadj[i+2][j+1].push_back({i,j});
                }

                if(j-1 >=1 && i+2 <= h && board[i+2][j-1]==0){
                    hadj[i][j].push_back({i+2,j-1});
                    hadj[i+2][j-1].push_back({i,j});
                }

                if(j-2 >=1 && i+1 <= h && board[i+1][j-2]==0){
                    hadj[i][j].push_back({i+1,j-2});
                    hadj[i+1][j-2].push_back({i,j});
                }

                if(j-2 >=1 && i-1 >=1 && board[i-1][j-2]==0){
                    hadj[i][j].push_back({i-1,j-2});
                    hadj[i-1][j-2].push_back({i,j});
                }
    
                if(j-1 >=1 && i-2 >=1 && board[i-2][j-1]==0){
                    hadj[i][j].push_back({i-2,j-1});
                    hadj[i-2][j-1].push_back({i,j});
                }
            }
        }
    }

    visited[1][1][0]=true;
    dist[1][1][0]=0;
    q.push({{1,1},0});

    while(!q.empty()){
        auto s = q.front(); q.pop();
        if(s.first.first == h && s.first.second == w){
            mx.push_back(dist[s.first.first][s.first.second][s.second]);
            // cout << dist[s.first.first][s.first.second][s.second];
            // return 0;
        }
        if(s.second<k){
            for(auto u : hadj[s.first.first][s.first.second]){
                int a = u.first;
                int b = u.second;

                if(visited[a][b][s.second+1])continue;
                visited[a][b][s.second+1]=true;
                dist[a][b][s.second+1]=dist[s.first.first][s.first.second][s.second]+1;
                q.push({{a,b},s.second+1});
            }   
        }
        
        for(auto u : adj[s.first.first][s.first.second]){
            int a = u.first;
            int b = u.second;

            if(visited[a][b][s.second])continue;
            visited[a][b][s.second]=true;
            dist[a][b][s.second]=dist[s.first.first][s.first.second][s.second]+1;
            q.push({{a,b},s.second});
        }

    }
    sort(mx.begin(),mx.end());
    if(mx.size()!=0){
        cout << mx[0];
    }
    else{
        cout << -1;
    }
    //cout << -1;
    
    return 0;
}