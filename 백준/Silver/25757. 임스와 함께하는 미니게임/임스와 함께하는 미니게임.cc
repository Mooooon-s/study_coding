#include <bits/stdc++.h>

using namespace std;

vector<string> ids;

map<string,int> ides;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    char game;
    cin >> n;
    cin >> game;

    for(int i=0;i<n;i++){
        string id;
        cin >> id;
        if(ides.find(id)==ides.end()){
            ides.insert({id,1});
        }
    }

    switch (game) {
        case 'Y':
            {
                cout << ides.size()/1;
                break;
            }
        case 'F':
            {
                cout << ides.size()/2;
                break;
            }
        case 'O':
            {
                cout << ides.size()/3;
                break;
            }
    }
    

    return 0;
}