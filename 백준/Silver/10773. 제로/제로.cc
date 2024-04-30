#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> bank;
    int n;
    cin >>n;

    for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            
            if(tmp!=0)
                bank.push_back(tmp);
            else
                bank.pop_back();
        }

    long long total=0;
    for(auto b : bank)
        total+=b;

    cout << total;

    
    return 0;
}