#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<pair<int,int>> P;

    int N;

    cin >> N;

    for(int i=0;i<N;i++)
        {
            int time;
            cin >> time;
            P.push_back(make_pair(time,i));
        }

    sort(P.begin(),P.end());

    int preTime=0;
    int result =0;
    for(int i=0;i<N;i++)
        {
            preTime+=P[i].first;
            result +=preTime;
        }
    
    std::cout << result;
    return 0;
}