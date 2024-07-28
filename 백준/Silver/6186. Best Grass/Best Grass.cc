#include <bits/stdc++.h>

using namespace std;

#define MAX 101

typedef pair<int,int> pii;

char grass[MAX][MAX];

vector<pii> adj[MAX][MAX];

queue<pii> q;

bool visited[MAX][MAX];

int main(void){
    int r,c;
    cin >> r >> c;

    for(int i=1;i<=r;i++){
        string s;
        cin >> s;
        for(int j=1;j<=c;j++){
            grass[i][j]=s[j-1];
            if(grass[i][j]=='#'){
                if(i-1>0 && grass[i-1][j]=='#'){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }
    
                if(j-1>0 && grass[i][j-1]=='#'){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                }
            }
        }
    }

    int cnt=0;

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(grass[i][j]=='#' && !visited[i][j]){
                q.push({i,j});
                visited[i][j]=true;
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

    cout << cnt;
    
    return 0;
}