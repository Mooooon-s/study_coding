#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N , K;
    cin >> N >> K;
    int* sencers = new int[N];
    int* Dir = new int[N-1];

    for(int i=0;i<N;i++)
        {
            cin >> sencers[i];
        }

    sort(sencers,sencers+N);
    //for(int i=0;i<N;i++)
    //    {
    //        cout << sencers[i] << " ";
    //    }
    //cout <<'\n';

    for(int i=0;i<N-1;i++)
        {
            Dir[i] = sencers[i+1] - sencers[i];
        }

    sort(Dir,Dir+(N-1));
    //for(int i=0;i<N-1;i++)
    //    {
    //        cout << Dir[i] << " ";
    //    }
    //cout << "\n";
    
    int result =0;
    for(int i=0;i<(N-1)-(K-1);i++)
        {
            result+=Dir[i];
        }

    std::cout << result;
    return 0;
}