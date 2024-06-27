#include <bits/stdc++.h>

using namespace std;

#define MAX 101

typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
vector<pii> Radj[MAX][MAX];

queue<pii> q;

char board[MAX][MAX];
bool visited[MAX][MAX];

int main(void){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> board[i][j];
            if(board[i][j]=='R'){
                if(i-1 >=1&& board[i-1][j]=='R'){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                    Radj[i][j].push_back({i-1,j});
                    Radj[i-1][j].push_back({i,j});                    
                }
                if(j-1 >=1&& board[i][j-1]=='R'){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                    Radj[i][j].push_back({i,j-1});
                    Radj[i][j-1].push_back({i,j});
                }

               if(i-1 >=1&& board[i-1][j]=='G'){
                    Radj[i][j].push_back({i-1,j});
                    Radj[i-1][j].push_back({i,j});
                }
                if(j-1 >=1&& board[i][j-1]=='G'){
                    Radj[i][j].push_back({i,j-1});
                    Radj[i][j-1].push_back({i,j});
                }
                
            }
            if(board[i][j]=='G'){
                if(i-1 >=1&& board[i-1][j]=='G'){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                    Radj[i][j].push_back({i-1,j});
                    Radj[i-1][j].push_back({i,j});   
                }
                if(j-1 >=1&& board[i][j-1]=='G'){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                    Radj[i][j].push_back({i,j-1});
                    Radj[i][j-1].push_back({i,j});
                }
               if(i-1 >=1&& board[i-1][j]=='R'){
                    Radj[i][j].push_back({i-1,j});
                    Radj[i-1][j].push_back({i,j});
                }
                if(j-1 >=1&& board[i][j-1]=='R'){
                    Radj[i][j].push_back({i,j-1});
                    Radj[i][j-1].push_back({i,j});
                }                
            }
            if(board[i][j]=='B'){
                if(i-1 >=1&& board[i-1][j]=='B'){
                    adj[i][j].push_back({i-1,j});
                    adj[i-1][j].push_back({i,j});
                    Radj[i][j].push_back({i-1,j});
                    Radj[i-1][j].push_back({i,j});
                }
                if(j-1 >=1&& board[i][j-1]=='B'){
                    adj[i][j].push_back({i,j-1});
                    adj[i][j-1].push_back({i,j});
                    Radj[i][j].push_back({i,j-1});
                    Radj[i][j-1].push_back({i,j});
                }
            }
        }
    }

    //for(int i=1;i<n;i++){
    //    for(int j=1;j<=n;j++){
    //        cout << board[i][j];
    //    }
    //    cout <<'\n';
    //}

    int cnt=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(board[i][j]=='R' && !visited[i][j]){
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

            if(board[i][j]=='G' && !visited[i][j]){
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

            if(board[i][j]=='B' && !visited[i][j]){
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

   for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visited[i][j]=false;
        }
    }

    cout << cnt << ' ';

    cnt=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((board[i][j]=='R' || board[i][j]=='G') && !visited[i][j]){
                visited[i][j]=true;
                q.push({i,j});
                cnt++;
                while(!q.empty()){
                    auto s = q.front(); q.pop();
                    for(auto u : Radj[s.first][s.second]){
                        int a = u.first;
                        int b = u.second;
                        if(visited[a][b])continue;
                        visited[a][b]=true;
                        q.push({a,b});
                    }
                }
            }

            
            if(board[i][j]=='B' && !visited[i][j]){
                visited[i][j]=true;
                q.push({i,j});
                cnt++;
                while(!q.empty()){
                    auto s = q.front(); q.pop();
                    for(auto u : Radj[s.first][s.second]){
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