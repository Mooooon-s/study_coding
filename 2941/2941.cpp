#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){
    vector<string> c ={"c=","c-","dz=","d-","lj","nj","s=","z="};
    int index;
    string in;
    cin>>in;
    
    
    for(int i=0; i<c.size(); i++){
        while(1){
            index=in.find(c[i]);
            if(index==string::npos)
                break;
            in.replace(index,c[i].length(),"#");
        }
    }
    cout<<in.size();
    return 0;
}