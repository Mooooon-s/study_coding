#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    //std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

    vector<int> queue;
    string input;
    int n,m;

    queue.resize(0);

    cin>>n;
    for(size_t i = 0; i<n;i++)
    {
        cin>>input;

        if(input == "push")
        {
            cin>> m;
            queue.push_back(m);
        }

        if(input == "pop")
        {
            if(queue.size()!=0)
            {
                auto f = queue.begin();
                cout<<*f;
                queue.erase(queue.begin());
            }
            else
            {
                cout<< -1;
                
            }
            cout<<endl;
        }

        if(input == "size")
        {
            cout<<queue.size();
            cout<<endl;
        }

        if(input == "empty")
        {
            if(queue.empty())
                cout<<1;
            else
                cout<<0;
            cout<<endl;
        }

        if(input == "front")
        {
            if(queue.empty())
                cout<<-1;
            else
                cout<<*queue.begin();
            cout<<endl;
        }

        if(input == "back")
        {
            if(queue.empty())
                cout<<-1;
            else
                cout<<*(queue.end()-1);
            cout<<endl;
        }
    }

    return 0;

}