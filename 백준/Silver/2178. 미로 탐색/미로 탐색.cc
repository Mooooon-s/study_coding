#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dist[101][101];
string maze[101];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<101;i++)
        for(int j=0;j<101;j++)
            dist[i][j]=-1;

    int N,M;
    cin >> N >> M;
    for(int i=0;i<N;i++)
        {
            cin>>maze[i];
        }
    
    queue<pair<int,int>> Q;
    Q.push({0,0});
    dist[0][0]=1;
    while(!Q.empty())
        {
            pair<int,int> cur = Q.front();Q.pop();
            for(int i=0;i<4;i++)
                {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx < 0 || nx >=N || ny < 0 || ny >=M)continue;
                    if(dist[nx][ny]>=0 || maze[nx][ny]!='1')continue;
                    dist[nx][ny]=dist[cur.first][cur.second]+1;
                    Q.push({nx,ny});
                }
        }

    cout << dist[N-1][M-1];
    
    return 0;
}