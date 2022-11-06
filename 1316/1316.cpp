#include<iostream>
#include<string>;

using namespace std;

int main(void){
    int     n;
    int     count=0;
    string  s;
    
    
    cin>>n;
    for(int i=0;i<n;i++){
        count++;
        int flag[26]={0};
        cin>>s;
        for(int j=0;j<s.size();j++){
            int index=s[j]-97;
            if(flag[index]!=1){
                flag[index]=1;
            }
            else
            {
                if(s[j]!=s[j-1]){
                    flag[index]=0;
                    count--;
                    break;
                }
            }
        }
    }
    cout<<count;
}