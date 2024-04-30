#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> vec;

int main()
{
    int n,a;
    string com;
    cin >> n;
    for(size_t i = 0;i<n;i++)
    {
        cin>>com;
        Action(com);
    }
    return 0;
}

void Action(const string commend)
{
    if(commend == "push_front")
    {
        int m=0;
        cin>>m;
        vec.insert(vec.begin(),m);
    }

    if(commend== "push_back")
    {
        int m=0;
        cin>>m;
        vec.push_back(m);
    }

    if(commend== "pop_front")
    {
        if(vec.size()==0)
        {
            cout<< -1;
            return;
        }

        vec.erase(vec.begin());
    }

    if(commend == "pop_back")
    {
        if(vec.size()==0)
        {
            cout<< -1;
            return;
        }

        vec.pop_back();
    }

    if(commend == "size")
    {
        cout<<vec.size();
    }

    if(commend == "empty")
    {
        if(vec.empty())
            cout << 1;
        else
            cout << 0;
    }

    if(commend == "front")
    {
        if(vec.size()==0)
        {
            cout<< -1;
            return;
        }

        cout<< *(vec.begin());
    }

    if(commend == "back")
    {
        if(vec.size()==0)
        {
            cout<< -1;
            return;
        }

        cout << vec.back();
    }

}