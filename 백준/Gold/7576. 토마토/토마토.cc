#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N,M;
queue<pair<int,int>> Q;
int vis[1002][1002];
int board[1002][1002];
int date = -1;
int main() {
    cin >> M >> N;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            {
                cin>>board[i][j];
                if(board[i][j]==1)
                    Q.push({i,j});
                if(board[i][j]==0)
                    vis[i][j]=-1;
            }

    while(!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            for(int i=0;i<4;i++)
                {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx<0 || nx >= N || ny < 0 || ny >= M)continue;
                    if(vis[nx][ny]>=0)continue;
                    vis[nx][ny]=vis[cur.first][cur.second]+1;
                    Q.push({nx,ny});
                }       
        }
    
    for(int i=0;i<N;i++)
        {
        for(int j=0;j<M;j++)
            {
                if(date < vis[i][j])
                    date = vis[i][j];
                if(vis[i][j]==-1)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
        cout << date;
    
    return 0;
}