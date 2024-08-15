#include <bits/stdc++.h>

using namespace std;

#define MAX 101

string str;

int main(){
    cin >> str;
    int count = str.size();
    if(count %2 !=0)
        count = (count / 2) +1;

    //cout << count << '\n';
    int flag=1;
    for(int i=0;i<count;i++){
        //cout << i << ' ' << str[i] << ' ' << str[(str.size()-1)-i] << '\n';
        if(str[i] != str[(str.size()-1)-i]){
            flag=0;
            break;
        }
    }

    cout << flag;
        
    
    return 0;
}