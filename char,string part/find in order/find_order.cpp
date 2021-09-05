#include<iostream>
#include<string>
#define MAX 100
using namespace std;

int main(void){
    string str;
    int index;
    cin>>str;
    for(int i=0;i<26;i++){
        index=str.find('a'+i);
        cout<<index<<" ";
    }

    return 0;
}