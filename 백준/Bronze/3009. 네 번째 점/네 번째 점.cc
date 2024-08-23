#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;

int main(){
    for(int i=0;i<3;i++){
        int a,b;
        cin >> a>> b;
        v.push_back(make_pair(a,b));
    }

    int minX=987654321;
    int minY=987654321;
    int maxX=0;
    int maxY=0;
    
    for(int i=0;i<3;i++){
        minX = min(minX,v[i].first);
        minY = min(minY,v[i].second);
        maxX = max(maxX,v[i].first);
        maxY = max(maxY,v[i].second);
    }

    vector<pair<int,int>> c;
    c.push_back(make_pair(minX,minY));
    c.push_back(make_pair(minX,maxY));
    
    c.push_back(make_pair(maxX,minY));
    c.push_back(make_pair(maxX,maxY));

    for(int i=0;i<4;i++){
        int flag =0;
        for(int j=0;j<3;j++){
            if(c[i]==v[j])
            {
                flag=1;
                break;
            }
        }
            if(!flag){
                cout << c[i].first << ' ' << c[i].second;
                break;
            }
    }
    
    return 0;
}