#include<iostream>
#include <string.h>
using namespace std;

int main(){
    int num=0;
    int n=0;
    string a;
    getline(cin,a);
    while(a.at(n) !='\0'){
        if(a.compare(n,1," ")==0){
            if(n==0||n==a.size()-1){
                
            }
            else{
                num++;
            }
        }
        if(n<a.size()-1)
            n++;
        else
            break;
    }

    if(a.size()==1){
        if(a.compare(0,1," ")==0){
            cout<<num;
        }
        else
            cout<<num+1;
    }
    else
        cout<<num+1;
    return 0;
}