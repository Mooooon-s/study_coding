#include <bits/stdc++.h>

using namespace std;

void InputWebPass(int a);
string FindPassward();

int nw,np;
map<string,string> note;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> nw >> np;
    InputWebPass(nw);

    for(int i=0;i<np;i++){
        cout << FindPassward() << '\n';
    }
    
    return 0;
}

void InputWebPass(int a){
    for(int i=0;i<a;i++){
        string web,passward;
        cin >> web >> passward;
        note.insert({web,passward});
    }
}

string FindPassward(){
    string web;
    cin >> web;

    return note.find(web)->second;
}