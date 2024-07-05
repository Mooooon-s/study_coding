#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

#define MAX 101

vector<pii> adj[MAX][MAX];
vector<pii> wateradj[MAX][MAX];
vector<int> bridge;

queue<pii> q;
queue<pii> wq;

bool visited[MAX][MAX];
bool watervisited[MAX][MAX];

int waterdist[MAX][MAX];
int dist[MAX][MAX];

int board[MAX][MAX];
int sideboard[MAX][MAX];

int main(){
    int n;
    cin >>n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
            if(board[i][j]==0){
                if(i-1>=1 && board[i-1][j]!=0){
                    sideboard[i-1][j]=1;
                }

                if(j-1>=1 && board[i][j-1]!=0){
                    sideboard[i][j-1]=1;
                }
            }

            if(board[i][j]!=0){
                if(i-1>=1 && board[i-1][j]==0){
                    sideboard[i][j]=1;
                }

                if(j-1>=1 && board[i][j-1]==0){
                    sideboard[i][j]=1;
                }
                if(i-1>=1 && board[i-1][j]!=0){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }

                if(j-1>=1 && board[i][j-1]!=0){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                }
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-1>=1){
                wateradj[i][j].push_back({i-1,j});
                wateradj[i-1][j].push_back({i,j});
            }
            if(j-1>=1){
                wateradj[i][j].push_back({i,j-1});
                wateradj[i][j-1].push_back({i,j});
            }
        }
    }

    int land=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j]!=0 && !visited[i][j]){
                visited[i][j]=true;
                dist[i][j]=++land;
                q.push({i,j});

                while(!q.empty()){
                    auto s = q.front(); q.pop();
                    for(auto u : adj[s.first][s.second]){
                        int a = u.first;
                        int b = u.second;
                        if(visited[a][b])continue;
                        dist[a][b]=land;
                        visited[a][b]=true;
                        q.push({a,b});
                    }
                }
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << board[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << sideboard[i][j];
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << dist[i][j];
    //     }
    //     cout << '\n';
    // }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            
            for(int k=1;k<=n;k++){
                for(int l=1;l<=n;l++){
                    watervisited[k][l]=false;
                    waterdist[k][l]=0;
                }
            }

            while(!wq.empty()) wq.pop();

            if(sideboard[i][j]!=0 && !watervisited[i][j]){
                watervisited[i][j]=true;
                waterdist[i][j]=0;
                int lands = dist[i][j];
                wq.push({i,j});

                while(!wq.empty()){
                    auto s = wq.front(); wq.pop();
                    if(dist[s.first][s.second]!=0 && dist[s.first][s.second] !=lands){
                        bridge.push_back(waterdist[s.first][s.second]);
                        break;
                    }
                    for(auto u : wateradj[s.first][s.second]){
                        int a = u.first;
                        int b = u.second;
                        if(watervisited[a][b])continue;
                        if(lands==dist[a][b])continue;
                        watervisited[a][b]=true;
                        waterdist[a][b]=waterdist[s.first][s.second]+1;
                        wq.push({a,b});
                    }
                }

                // cout << '\n';
                // for(int i=1;i<=n;i++){
                //     for(int j=1;j<=n;j++){
                //         cout << waterdist[i][j];
                //     }
                //     cout << '\n';
                // }

                //cout << bridge[bridge.size()-1];
            }
        }
    }

    sort(bridge.begin(),bridge.end());

    cout << bridge[0]-1;
    
    return  0;
}