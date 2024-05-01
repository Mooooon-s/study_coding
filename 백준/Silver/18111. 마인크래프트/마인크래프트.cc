#include <iostream>
#include <cmath>

//블록을 제거하는데 2초
//블록을 쌓는데 1초
//최대 높이는 256

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    
    int n,m;
    long long b;

  
    cin >> n >> m >> b;

    int arr[501][501] = {0,};
    int min = 0x7f7f7f7f;
    int height =-1;

    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                {
                    cin >> arr[i][j];
                }
        }

    for(int i=0;i<=256;i++)
        {
            int build=0;
            int remove=0;
            for(int j=0;j<n;j++)
                {
                    for(int k=0;k<m;k++)
                        {
                                if(arr[j][k] - i  < 0)
                                    build -= (arr[j][k]-i);
                                else if(arr[j][k] - i > 0)
                                    remove += (arr[j][k] - i);
                        }
                }

            if((b+ remove) >= build)
            {
                int total = (build) + (remove *2);
                if(total <= min)
                {
                    min = total;
                    height = i;
                }
            }
        }

    cout << min << " " << height;
    
    
    return 0;
}