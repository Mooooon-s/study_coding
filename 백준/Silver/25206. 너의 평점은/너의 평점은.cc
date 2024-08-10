#include <bits/stdc++.h>

using namespace std;

typedef pair<int,string> pis;

map<string,pis> score;

float result;

float ss;

string buf;

int split(string b){
    istringstream ss(b);
    string buff;
    vector<string> v;
    while(getline(ss,buff,' ')){
        v.push_back(buff);
    }
    score.insert({v[0],{stoi(v[1]),v[2]}});

    return true;
}


float calc(pis p){
    float a,b,c;
    if(p.second == "A+")
        a= 4.5;
    else if(p.second == "A0")
        a= 4.0;
    else if(p.second == "B+")
        a= 3.5;
    else if(p.second == "B0")
        a= 3.0;
    else if(p.second == "C+")
        a= 2.5;
    else if(p.second == "C0")
        a= 2.0;
    else if(p.second == "D+")
        a = 1.5;
    else if(p.second == "D0")
        a= 1.0;
    else if(p.second == "F")
        a = 0.0;
    else if(p.second == "P")
        a = -1.0;

    
    if(a>=0){
        ss+=p.first;
        return p.first * a;
    }
    else 
        return a;
}

int main(){
    int cnt=0;
    while(getline(cin,buf)){
        split(buf);
    }

    for(auto s : score){
        // cout << s.first << ' ' << s.second.first << ' ' << s.second.second <<'\n';
        float tmp = calc(s.second);
        if(tmp>=0){
            result+=tmp;
        }
    }

    if(result>0)
        cout << result/ss;
    else
        cout << 0;
    
    return 0;
}