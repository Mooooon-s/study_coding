#include<iostream>
using namespace std;

int main(){
    int num=0;
    int n=0;
    string a;
    getline(cin,a);
    while(a.at(n) !='\0'){
        if(a.compare(n,1," ")==0){
            num++;
        }
        if(n<a.size()-1)
            n++;
        else
            break;
    }
    cout<<num+1;
    return 0;
}