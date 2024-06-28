#include <bits/stdc++.h>

using namespace std;

#define MAX 301

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
queue<pii> q;

bool visited[MAX][MAX];
int dist[MAX][MAX];

int board[MAX][MAX];

int main(){
    int t;
    cin>> t;

    for(int i=0;i<t;i++){
        int l;
        cin >> l;

        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                board[i][j]=0;
                visited[i][j]=false;
                dist[i][j]=0;
                adj[i][j].clear();
            }
        }
        
        int s1,s2;
        cin >> s1 >> s2;
        board[s1][s2]=1;
        int e1,e2;
        cin >> e1 >> e2;
        board[e1][e2]=2;

        for(int j=0;j<l;j++){
            for(int k=0;k<l;k++){
                if(board[j][k]==1){
                    q.push({j,k});
                    visited[j][k]=true;
                    dist[j][k]=0;
                    if((j-2 >=0 && k-1 >=0)&&board[j-2][k-1]!=1){
                        adj[j][k].push_back({j-2,k-1});
                    }
                    if((j-1 >=0 && k-2 >=0)&&board[j-1][k-2]!=1){
                        adj[j][k].push_back({j-1,k-2});
                    }
                    if((j+1 <l && k-2 >=0)&&board[j+1][k-2]!=1){
                        adj[j][k].push_back({j+1,k-2});
                    }
                    if((j+2 <l && k-1 >=0)&&board[j+2][k-1]!=1){
                        adj[j][k].push_back({j+2,k-1});
                    }
                    if((j+2 <l && k+1 <l)&&board[j+2][k+1]!=1){
                        adj[j][k].push_back({j+2,k+1});
                    }
                    if((j+1 <l && k+2 <l)&&board[j+1][k+2]!=1){
                        adj[j][k].push_back({j+1,k+2});
                    }
                    if((j-1 >=0 && k+2 <l)&&board[j-1][k+2]!=1){
                        adj[j][k].push_back({j-1,k+2});
                    }
                    if((j-2 >=0 && k+1 <l)&&board[j-2][k+1]!=1){
                        adj[j][k].push_back({j-2,k+1});
                    }
                }

                if(board[j][k]==0){
                    if((j-2 >=0 && k-1 >=0)&&board[j-2][k-1]!=1){
                        adj[j][k].push_back({j-2,k-1});
                    }
                    if((j-1 >=0 && k-2 >=0)&&board[j-1][k-2]!=1){
                        adj[j][k].push_back({j-1,k-2});
                    }
                    if((j+1 <l && k-2 >=0)&&board[j+1][k-2]!=1){
                        adj[j][k].push_back({j+1,k-2});
                    }
                    if((j+2 <l && k-1 >=0)&&board[j+2][k-1]!=1){
                        adj[j][k].push_back({j+2,k-1});
                    }
                    if((j+2 <l && k+1 <l)&&board[j+2][k+1]!=1){
                        adj[j][k].push_back({j+2,k+1});
                    }
                    if((j+1 <l && k+2 <l)&&board[j+1][k+2]!=1){
                        adj[j][k].push_back({j+1,k+2});
                    }
                    if((j-1 >=0 && k+2 <l)&&board[j-1][k+2]!=1){
                        adj[j][k].push_back({j-1,k+2});
                    }
                    if((j-2 >=0 && k+1 <l)&&board[j-2][k+1]!=1){
                        adj[j][k].push_back({j-2,k+1});
                    }
                }
            }
        }

        while(!q.empty()){
            auto s = q.front(); q.pop();
            for(auto u : adj[s.first][s.second]){
                int a = u.first;
                int b = u.second;
                if(visited[a][b])continue;
                visited[a][b]=true;
                dist[a][b]=dist[s.first][s.second]+1;
                q.push({a,b});
            }
        }

        cout << dist[e1][e2] << '\n';
    }
    
    return 0;
}