#include <bits/stdc++.h>

using namespace std;

#define MAX 26

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
queue<pii> q;

int board[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int main(void){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            board[i][j]= s[j] -'0';
            if(board[i][j]==1){
                if(i-1 >=0 && board[i-1][j]==1){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }

                if(j-1>=0 && board[i][j-1]==1){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                }
            }
        }
    }

    int cnt=0;
    vector<int> w;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==1 && !visited[i][j]){
                int mx=1;
                visited[i][j]=true;
                dist[i][j]=mx;
                q.push({i,j});
                cnt++;

                while(!q.empty()){
                    auto s = q.front(); q.pop();
                    for(auto u : adj[s.first][s.second]){
                        int a =u.first;
                        int b = u.second;
                        if(visited[a][b])continue;
                        dist[a][b]=++mx;
                        visited[a][b]=true;
                        q.push({a,b});
                    }
                }
                
                w.push_back(mx);
            }
        }
    }

    //for(int i=0;i<n;i++){
        //for(int j=0;j<n;j++){
            //cout << dist[i][j]<<' ';
        //}
        //cout << '\n';
    //}
    
    sort(w.begin(),w.end());
    cout << cnt << '\n';
    for(int i=0;i<w.size();i++){
        cout << w[i] << '\n';
    }
    
    
    return 0;
}