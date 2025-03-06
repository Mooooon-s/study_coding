#include <bits/stdc++.h>

using namespace std;

vector<char> gather = {'a','e','i','o','u'};

int main(){
    while(1){
        cin.tie(0);
        ios::sync_with_stdio(false);
        string pw;
        cin>>pw;
        if(pw=="end") break;

        bool flag=false;
        int cnt=0;

        for(int i=0;i<pw.size();i++){
            if(find(gather.begin(),gather.end(),pw[i])!=gather.end()){
                flag = true;
            }
        }

        if(!flag){
            cout << '<' << pw << "> is not acceptable.\n";
            //cout << "( code 1 )\n";
            continue;
        }

        for(int i=1;i<pw.size();i++){
            if(find(gather.begin(),gather.end(),pw[i])!=gather.end()
                && find(gather.begin(),gather.end(),pw[i-1])!=gather.end())
            {
                cnt++;
            }
            else{
                cnt=0;
            }

            if(cnt==2){
                flag=false;
            }
        }

        if(!flag){
            cout << '<' << pw << "> is not acceptable.\n";
            //cout << "( code 2 )\n";
            continue;
        }

        cnt=0;
        for(int i=1;i<pw.size();i++){
            if(find(gather.begin(),gather.end(),pw[i])==gather.end()
                && find(gather.begin(),gather.end(),pw[i-1])==gather.end())
            {
                cnt++;
            }
            else{
                cnt=0;
            }

            if(cnt==2){
                flag=false;
            }
        }

        if(!flag){
            cout << '<' << pw << "> is not acceptable.\n";
            //cout << "( code 2-1 )\n";
            continue;
        }

        for(int i=1;i<pw.size();i++){
            if(pw[i-1] == pw[i])
            {
                if(pw[i]=='e' || pw[i]=='o'){
                    continue;
                }
                else{
                    flag=false;
                }
            }
        }

        if(!flag){
            cout << '<' << pw << "> is not acceptable.\n";
            //cout << "( code 3 )\n";
            continue;
        }
        else{
            cout << '<' << pw << "> is acceptable.\n";
        }
        
    }

    return 0;
}