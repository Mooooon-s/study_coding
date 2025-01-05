#include <bits/stdc++.h>

#define MAX 301

using namespace std;

int main(){
    string str;
    cin >> str;

    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=('a'-'A');
        else if(str[i]>='a' && str[i]<='z')
            str[i]-=('a'-'A');
    }

    cout << str;
    return 0;
}