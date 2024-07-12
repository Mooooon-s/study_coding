#include <iostream>

using namespace std;

int integer[27];

int main() {
    string s;
    cin >> s;

    for(int i=0;i<=s.size();i++){
        integer[s[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        cout << integer[i] << ' ';
    }
    
    return 0;
}