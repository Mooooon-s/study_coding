#include <bits/stdc++.h>

#define MAX 51

using namespace std;


typedef pair<int,int> pii;

vector<pii> adj[MAX][MAX];
int visited[MAX][MAX]={0,};
int board[MAX][MAX];

queue<pii> q;

int w,h;


void InputMap();
void MakeAdj();
int dfs(int a,int b);

int result=0;

int main(void){
    int Case =0;
    while(1){
        //reset
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                board[i][j]=0;
                visited[i][j]=0;
                adj[i][j].clear();
            }
        }
        Case++;
        result =0;

        cin >> w >> h;
        if(w==0 && h==0)
            return 0;
        
        InputMap();      
        MakeAdj();

        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(board[i][j]==1 && visited[i][j]==0){
                    result+=dfs(i,j);
                }
            }
        }
        cout << result << '\n';
    }
}

void InputMap(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> board[i][j];
        }
    }
}

void MakeAdj(){
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(board[i][j]==1){   
                //left
                if(j-1>0 && board[i][j-1]==1){
                    adj[i][j-1].push_back({i,j});
                    adj[i][j].push_back({i,j-1});
                }
                //up
                if(i-1>0 && board[i-1][j]==1){
                    adj[i-1][j].push_back({i,j});
                    adj[i][j].push_back({i-1,j});
                }
                //left_top
                if(j-1>0 && i-1>0&& board[i-1][j-1]==1){
                    adj[i-1][j-1].push_back({i,j});
                    adj[i][j].push_back({i-1,j-1});
                }
                //left_bottom
                if(j-1>0 && i+1>0&& board[i+1][j-1]==1){
                    adj[i+1][j-1].push_back({i,j});
                    adj[i][j].push_back({i+1,j-1});
                }
            }
        }
    }
}

int dfs(int a,int b){
    q.push({a,b});
    visited[a][b]=1;
    int cnt=0;
    while(!q.empty()){
        cnt++;
        auto s = q.front(); q.pop();
        for(auto u : adj[s.first][s.second]){
            int f = u.first;
            int s = u.second;
            if(visited[f][s]!=0) continue;
            visited[f][s]=1;
            q.push({f,s});
        }
    }
    if(cnt==0){
        return 0;
    }
    else{
        return 1;
    }
}