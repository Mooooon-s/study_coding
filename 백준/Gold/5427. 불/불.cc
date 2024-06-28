#include <bits/stdc++.h>

using namespace std;

#define MAX 1002
#define INF 987654321
typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
vector<pii> fadj[MAX][MAX];
queue<pii> q;
queue<pii> fq;

bool visited[MAX][MAX];
bool fvisited[MAX][MAX];
int dist[MAX][MAX];
int fdist[MAX][MAX];

char board[MAX][MAX];


int main(void){
    int t;
    cin >> t;

    for(int cases = 0; cases < t; cases++){
        int w,h;
        cin >> w >> h;

        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                fdist[i][j]=INF;
                dist[i][j]=INF;
                adj[i][j].clear();
                fadj[i][j].clear();
                visited[i][j]=false;
                fvisited[i][j]=false;
            }
        }

        while(!q.empty())   q.pop();

        while(!fq.empty())   fq.pop();


        
        for(int i=1;i<=h;i++){
            string s;
            cin>>s;
            for(int j=1;j<=w;j++){
                board[i][j]=s[j-1];
                //fdist[i][j]=-1;
                dist[i][j]=-1;
                if(board[i][j]=='*'){
                    fvisited[i][j]=true;
                    fdist[i][j]=0;
                    fq.push({i,j});
                    if(i-1 >=1 && board[i-1][j]!='#'){
                        fadj[i][j].push_back({i-1,j});
                        fadj[i-1][j].push_back({i,j});
                    }
                    if(j-1>=1 && board[i][j-1]!='#'){
                        fadj[i][j].push_back({i,j-1});
                        fadj[i][j-1].push_back({i,j});
                    }
                }

                if(board[i][j]=='.'){
                    if(i-1 >=1 && board[i-1][j]!='#'){
                        fadj[i-1][j].push_back({i,j});
                        fadj[i][j].push_back({i-1,j});
                        adj[i-1][j].push_back({i,j});
                        adj[i][j].push_back({i-1,j});
                    }
                    if(j-1>=1 && board[i][j-1]!='#'){
                        fadj[i][j-1].push_back({i,j});       
                        fadj[i][j].push_back({i,j-1});
                        adj[i][j-1].push_back({i,j});
                        adj[i][j].push_back({i,j-1});
                    }
                }
                    
                if(board[i][j]=='@'){
                    visited[i][j]=true;
                    dist[i][j]=0;
                    q.push({i,j});
                    if(i-1 >=1 && board[i-1][j]!='#'){
                        fadj[i-1][j].push_back({i,j});
                        fadj[i][j].push_back({i-1,j});
                        adj[i-1][j].push_back({i,j});
                        adj[i][j].push_back({i-1,j});
                        
                    }
                    if(j-1>=1 && board[i][j-1]!='#'){
                        fadj[i][j-1].push_back({i,j});
                        fadj[i][j].push_back({i,j-1});
                        adj[i][j-1].push_back({i,j});
                        adj[i][j].push_back({i,j-1});
                    }
                }
            }
        }
        
        for(int i=0;i<=h+1;i++){
            adj[i][1].push_back({i,0});
            adj[i][w].push_back({i,w+1});
            fadj[i][1].push_back({i,0});
            fadj[i][w].push_back({i,w+1});
        }

        for(int i=0;i<=w+1;i++){
            adj[1][i].push_back({0,i});
            adj[h][i].push_back({h+1,i});
            fadj[i][1].push_back({i,0});
            fadj[i][w].push_back({i,w+1});
        }

        while(!fq.empty()){
            auto s = fq.front(); fq.pop();
            for(auto u : fadj[s.first][s.second]){
                int a = u.first;
                int b = u.second;
                if(fvisited[a][b])continue;
                fvisited[a][b]=true;
                fdist[a][b]=fdist[s.first][s.second]+1;
                fq.push({a,b});
            }
        }

        bool flag=false;
        
        while(!q.empty()){
            auto s = q.front(); q.pop();
            if(s.first<=0 || s.second<=0 || s.first >=h+1 || s.second >= w+1){
                cout << dist[s.first][s.second]<<'\n';
                flag=true;
                break;
            }
            for(auto u : adj[s.first][s.second]){
                int a = u.first;
                int b= u.second;
                if(visited[a][b])continue;
                if(fdist[a][b]<=dist[s.first][s.second]+1)continue;
                visited[a][b]=true;
                dist[a][b]=dist[s.first][s.second]+1;
                q.push({a,b});
            }
        }

    if(!flag){
    
        for(int i=0;i<=h;i++){
            for(int j=0;j<=w;j++){
                //cout << fdist[i][j]<<' ';
            }
            //cout << '\n';
        }
    
            
        for(int i=0;i<=h+1;i++){
            for(int j=0;j<=w+1;j++){
                //cout << dist[i][j]<<' ';
            }
            //cout << '\n';
        }
    
        cout << "IMPOSSIBLE\n";
        
    }
}


    
    return 0;
}