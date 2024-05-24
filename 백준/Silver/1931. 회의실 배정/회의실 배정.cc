#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> arr;

int main(void)
{
    int N ,S ,E;
    int cnt=0;
    cin >> N;
    
    for(int i=0;i<N;i++)
        {
            cin >> S >> E;
            arr.push_back(make_pair(E,S));
        }
    
    sort(arr.begin(),arr.end());

    int time;
    time = arr[0].first;
    for(int i=1;i<N;i++)
        {
            if(time <= arr[i].second)
            {
                cnt++;
                time = arr[i].first;
            }
        }

    cout << cnt+1;

    return 0;
}