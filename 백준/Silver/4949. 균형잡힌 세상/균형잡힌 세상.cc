#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> _Sentance;
    vector<char> _Stack;
    string str;
    while(getline(cin , str))
        {
            _Sentance.push_back(str);
        }
    
    for(int i=0;i<_Sentance.size()-1;i++)
        {
            string s = _Sentance[i];
            int flag =0;
            
            _Stack.clear();
            for(int i=0;i<s.size();i++)
                {
                    if(s[i]=='[' || s[i]=='(')
                    {
                        _Stack.push_back(s[i]);
                        continue;
                    }
                    if(s[i]==']')
                    {
                        if(_Stack.back()=='[')
                            _Stack.pop_back();
                        else
                        {
                            flag =1;
                            break;
                        }
                    }
                    if(s[i]==')')
                    {
                        if(_Stack.back()=='(')
                            _Stack.pop_back();
                        else
                        {
                            flag=1;
                            break;
                        }
                    }
                }
            
            if(!flag && _Stack.empty())
                cout << "yes"<<endl;
            else
                cout << "no" <<endl;
        }
    
    return 0;
}