#include <bits/stdc++.h>

using namespace std;

#define MAX 101

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
queue<pii> q;

bool visited[MAX][MAX];
int dist[MAX][MAX];

int board[MAX][MAX];

vector<int> Size;

int main(){
    int m,n,k;
    cin >> m >>n >> k;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            for(int k=y1;k<y2;k++){
                for(int l=x1;l<x2;l++){
                    board[k][l]=1;
                }
            }
            
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0){
                if(i-1>=0 && board[i-1][j]==0){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                }
                if(j-1>=0 && board[i][j-1]==0){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                }
            }
        }
    }

    int cnt=0;
    

     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==0 && !visited[i][j]){
                cnt++;
                int d=1;
                visited[i][j];
                dist[i][j]=1;
                q.push({i,j});
                int mx=dist[i][j];
                while(!q.empty()){
                    auto s = q.front(); q.pop();
                    for(auto u : adj[s.first][s.second]){
                        int a = u.first;
                        int b = u.second;
                        if(visited[a][b])continue;
                        dist[a][b]=mx++;
                        visited[a][b]=true;
                        q.push({a,b});
                        d = max(d,dist[a][b]);
                    }
                }
                Size.push_back(d);
            }
        }
     }


    //for(int i=0;i<m;i++){
    //    for(int j=0;j<n;j++){
            //cout << dist[i][j]<<' ';
    //    }
        //cout <<'\n';
    //}


    sort(Size.begin(),Size.end());
    cout << cnt << '\n';
    for(int i=0;i<Size.size();i++){
        cout << Size[i]<<' ';
    }
    
    return 0;
}