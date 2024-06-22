#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
#define MAX 1002
#define INF 987654321

vector<pii> adj[MAX][MAX];

bool fire_visited[MAX][MAX];
bool visited[MAX][MAX];

queue<pii> fire_q;
queue<pii> q;

int dist[MAX][MAX];
int fire_dist[MAX][MAX];

char maze[MAX][MAX];

int main() {
    int r,c;
    cin >> r >> c;

    for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                fire_dist[i][j] = INF;
                cin>>maze[i][j];
                if(maze[i][j]=='J'){
                    visited[i][j]=true;
                    dist[i][j]=0;
                    q.push({i,j});
                }
                if(maze[i][j]=='F'){
                    fire_visited[i][j]=true;
                    fire_dist[i][j]=0;
                    fire_q.push({i,j});
                }
                if(maze[i][j]!='#'){
                    if(i-1 >= 1  && maze[i-1][j]!='#'){
                        adj[i][j].push_back({i-1,j});
                        adj[i-1][j].push_back({i,j});
                    }
                    if(j-1 >=1 && maze[i][j-1]!='#'){
                        adj[i][j].push_back({i,j-1});
                        adj[i][j-1].push_back({i,j});
                    }
                }    
            }
    }

    for(int i = 0;i<=r+1;i++){
        adj[i][1].push_back({i,0});
        adj[i][c].push_back({i,c+1});
        fire_dist[i][0] = INF;
        fire_dist[i][c+1] = INF;
        fire_visited[i][0] = true;
        fire_visited[i][c+1] = true;
    }

    for(int i = 0;i<=c+1;i++){
        adj[1][i].push_back({0,i});
        adj[r][i].push_back({r+1,i});
        fire_dist[0][i] = INF;
        fire_dist[r+1][i] = INF;
        fire_visited[0][i] = true;
        fire_visited[r+1][i] = true;
    }

    // cout << "input Done\n";

    while(!fire_q.empty()){
        auto s = fire_q.front(); fire_q.pop();
        for(auto u : adj[s.first][s.second]){
            int a = u.first;
            int b = u.second;
            if(fire_visited[a][b])continue;
            fire_visited[a][b]=true;
            fire_dist[a][b] = fire_dist[s.first][s.second]+1;
            fire_q.push({a,b});
        }
    }

    // cout << "F Done\n";

    // for(int i=1;i<=r;i++){
    //         for(int j=1;j<=c;j++){
    //             cout << fire_dist[i][j];
    //         }
    //     cout<<'\n';
    // }
    
    while(!q.empty()){
        auto s = q.front(); q.pop();
        // cout << "s: " << s.first << ' ' << s.second<< " dist: "<< dist[s.first][s.second] << '\n';
        if(s.first < 1 || s.second < 1 || s.first > r || s.second > c){
            cout << dist[s.first][s.second];
            return 0;
        }
        for(auto u : adj[s.first][s.second]){
            int a = u.first;
            int b = u.second;
            // cout << "s: " << s.first << ' ' << s.second<< " dist: "<< dist[s.first][s.second] << '\n';
            if(visited[a][b])continue;
            // cout << "a: " << a << ' ' << b << " dist: "<< dist[s.first][s.second]+1 <<'\n';
            if(fire_dist[a][b] <= dist[s.first][s.second]+1)continue;
            // cout << "a: " << a << ' ' << b << " dist: "<< dist[s.first][s.second]+1 <<'\n';
            visited[a][b]=true;
            dist[a][b] = dist[s.first][s.second]+1;
            q.push({a,b});
        }
    }
    // cout << "J Done\n";

    

    // for(int i=0;i<=r+1;i++){
    //         for(int j=0;j<=c+1;j++){
                
    //             cout << maze[i][j];
    //         }
    //     cout<<'\n';
    //     }
    // cout<<'\n';
    
    // for(int i=0;i<=r+1;i++){
    //         for(int j=0;j<=c+1;j++){
    //             cout << dist[i][j];
    //         }
    //     cout<<'\n';
    //     }
    // cout<<'\n';
    
    // for(int i=1;i<=r;i++){
    //         for(int j=1;j<=c;j++){
    //             cout << fire_dist[i][j];
    //         }
    //     cout<<'\n';
    //     }
    
    
    cout << "IMPOSSIBLE\n";
    return 0;
}