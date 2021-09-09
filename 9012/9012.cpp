#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(void){
    int T;
    cin>>T;
    int f=0,s=0;
    string ps;
    stack<char> ss;
    for(int i=0;i<T;i++){
        cin>>ps;
        bool flag = false;
        for(int k=0;k<ps.size();k++){
            if(ps[k]=='('){
                ss.push(ps[k]);
            }else if(ps[k]==')'){
                if(ss.empty()){
                    flag = true;
                    break;
                }
                if(ss.top()=='('){
                    ss.pop();
                }
            }
        }

        if(!ss.empty() || flag){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

        while(!ss.empty())
            ss.pop();
    }

    return 0;
}