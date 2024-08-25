#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int minX=987654321;
    int minY=987654321;
    int maxX=-100001;
    int maxY=-100001;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        if(minX > x)
            minX = x;
        if(minY > y)
            minY = y;
        if(maxX < x)
            maxX = x;
        if(maxY < y)
            maxY = y;
    }

    if(maxX == minX || maxY == minY)
        cout << 0;
    else
    {
        int result = (maxX - minX)* (maxY-minY);
        cout << result;
    }
    
    return 0;
}