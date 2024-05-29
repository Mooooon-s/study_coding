#include <iostream>

using namespace std;

int main() {

    int N , K;
    cin >> N >> K;

    int* order = new int[K];
    for(int i=0;i<K;i++)
        {
            cin >> order[i];
        }

    int* tap = new int[N];
    for(int k=0; k<N;k++)
        {
            tap[k]=0;
        }

    int cnt =0;
    for(int j=0;j<K;j++)
        {
            bool pass = false;
            for(int i=0;i<N;i++)
                {
                    if(order[j]==tap[i])
                    {
                        pass = true;
                        break;
                    }
                }
            if(pass) continue;

            for(int i=0;i<N;i++)
                {
                    if(tap[i]==0)
                    {
                        tap[i] = order[j];
                        pass = true;
                        break;
                    }
                }
            if(pass) continue;

            int pos = -1;
            int idx = -1;
            for(int i=0;i<N;i++)
                {
                    int tmp=0;
                    for(int k=j+1; k<K;k++)
                        {
                            if(tap[i] == order[k])break;
                            tmp++;
                        }
                    if(tmp > idx)
                    {
                        pos = i;
                        idx = tmp;
                    }
                }
            tap[pos] = order[j];
            cnt++;
        }

    cout << cnt;
    
    return 0;
}