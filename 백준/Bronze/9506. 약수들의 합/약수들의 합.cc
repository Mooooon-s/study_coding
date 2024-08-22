#include<bits/stdc++.h>

using namespace std;

#define MAX 100001

vector<int> v;

bool visitied[MAX];

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==-1)
            break;

        for(int i=1;i<n;i++){
            if(n%i==0){
                v.push_back(i);
            }
        }
        int result=0;
        sort(v.begin(),v.end());
        for(auto a : v){
            // cout << a << ' ';
            result+=a;
        }
        // cout << '\n' << result << '\n';
        if(result!=n)
            cout << n << " is NOT perfect.";
        else{
            cout << n << " = ";
            for(int i=0;i<v.size();i++){
                cout << v[i];
                if(i!=v.size()-1)
                    cout << " + ";
            }
        }
        cout <<'\n';

        v.clear();
    }
    return 0;
}