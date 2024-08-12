#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int matrix[2][MAX][MAX];

int main(){
    int n , m;
    cin >> n >> m;

    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> matrix[i][j][k];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[0][i][j] + matrix[1][i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}