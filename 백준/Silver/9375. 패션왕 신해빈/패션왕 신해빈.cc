#include <bits/stdc++.h>

using namespace std;

map<string,int> m;

int main(void){
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        m.clear();
        int optiion;
        cin >> optiion;
        for(int j=0;j<optiion;j++){
            string name , type;
            cin >> name >> type;
            if(m.find(type) == m.end())
            {
                m.insert({type,1});
            }
            else{
                m[type]++;
            }
        }
        int result=1;
        for(auto v : m){
            //cout << v.first<< ' ' << v.second << '\n';
            result *=(v.second+1);
        }

        cout << result-1 << '\n';
    }

    return 0;
}