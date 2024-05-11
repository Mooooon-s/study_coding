#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> name;
vector<string> names;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;

    cin >> n >> m;

    for(int i=0;i<n;i++)
        {
            string str;
            cin >> str;
            name.insert(make_pair(str,0));
        }

    for(int i = 0; i<m;i++)
        {
            string str;
            cin >> str;
            if(name.find(str) != name.end())
            {
                name.find(str)->second++;
            }
        }

    for(auto n : name)
        {
            if(n.second != 0)
                names.push_back(n.first);
        }

    cout << names.size() << '\n';
    for(auto n : names)
        {
            cout << n << '\n';
        }
    
    return 0;
}