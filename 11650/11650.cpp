#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{

    vector<pair<int,int>> vec;

    int n;
    cin>>n;


    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        vec.push_back(make_pair(a,b));
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<n;i++)
    {
        cout << vec[i].first<< " " << vec[i].second << '\n';
    }

    return 0;
}