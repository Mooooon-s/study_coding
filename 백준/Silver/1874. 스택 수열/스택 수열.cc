#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    int idx=1;
    int flag = 0;
    vector<int> _stack;
    vector<char> _operator;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >>m;
        while(idx <= m)
        {
             _stack.push_back(idx);
            idx++;
            _operator.push_back('+');
        }

        if(_stack.back() == m)
        {
            _stack.pop_back();
            _operator.push_back('-');
        }
        else
        {
            flag = 1;
        }

        if(flag)
            break;
    }
    if(flag)
        cout <<"NO";
    else
    {
        for(auto c : _operator)
            {
                 cout << c<< '\n';
            }
    }
    
    return 0;
}