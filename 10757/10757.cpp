#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    string s1,s2;
    int rest=0;
    cin>>s1>>s2;
    
    int max=s1.size() > s2.size() ? s1.size() : s2.size();
    vector<int> v1,v2;
    for(int i=0;i<max-s1.size();i++){
        v1.push_back(0);
    }
    
    for(int i=0;i<s1.size();i++){
        v1.push_back(s1[i]-'0');
    }
    
    for(int i=0;i<max-s2.size();i++){
        v2.push_back(0);
    }
    
    for(int i=0;i<s2.size();i++){
        v2.push_back(s2[i]-'0');
    }
    
    vector<int> result;
    
    for(int i=max-1;i>=0;i--){
        int a=v1.at(i);
        int b=v2.at(i);
        if(rest+a+b>=10){
            //cout<<rest+a+b<<"\n";
            result.push_back(((rest+a+b)%10));
            rest=1;
        }
        else{
            if(rest+a+b>=10){
                //cout<<rest+a+b<<"\n";
                result.push_back(((rest+a+b)%10));
                rest=1;
            }
            else{
                //cout<<rest+a+b<<"\n";
                result.push_back(rest+a+b);
                rest=0;
            }
        }
    }
    
    
    //cout<<"    "<<result[max]<<"\n";
    if(result[max]+rest!=0)
        result[max]+=rest;
    else
        max-=1;
    
    
    for(int i=max;i>=0;i--){
        cout<<result[i];
    }
    
    return 0;
}