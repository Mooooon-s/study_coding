#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    
    int n;
    map<int,int> card;

    cin>>n;

    for(size_t i =0;i<n;i++)
    {
        int c =0;
        cin>>c;
        card[c]++;
    }

    cin>>n;

    for(size_t i = 0; i < n ;i++)
    {
        int c=0;
        cin>>c;
        auto iter = card.find(c);
        if(iter == card.end())
            cout<< 0;
        else
            cout<< iter->second;
    }

    return 0;
}
