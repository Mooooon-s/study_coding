#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    int cnt=0;
    int row,col;
    int maxSize=0;
    int Size=0;
    int board[501][501];
    int vis[501][501];
    queue<pair<int,int>> Q;
    cin >> row >> col;
    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    cin >> board[i][j];
                }
        }

    for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                {
                    if(board[i][j]==0 || vis[i][j]==1) continue;
                    Q.push({i,j});
                    vis[i][j]=1;
                    cnt++;
                    while(!Q.empty())
                        {
                            pair<int,int> cur = Q.front();
                            Q.pop();
                            Size++;
                            for(int k=0;k<4;k++)
                                {
                                    int nx = cur.first + dx[k];
                                    int ny = cur.second + dy[k];
                                    
                                    if(nx<0||ny<0||nx>row||ny>col)continue;
                                    if(vis[nx][ny]==1||board[nx][ny]==0)continue;
                                    vis[nx][ny]=1;
                                    Q.push({nx,ny});
                                }
                        }
                    if(maxSize < Size)
                        maxSize=Size;
                    Size=0;
                }
        }

    cout << cnt << '\n';
    cout << maxSize;
    return 0;
}