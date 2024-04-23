#include <iostream>
#include <queue>

using namespace std;

int main() {
    int c, n , idx;
    cin >> c;

    while(c)
    {
        queue<pair<int,int>> que;
        cin >> n >> idx;

        for(int i=0;i<n;i++)
            {
                int temp;
                cin >>temp;
                que.push(make_pair(i , temp));
            }
        int cnt=1;
        while(1)
        {
            int m = 0;
            for(int i=0; i < que.size(); i++)
            {
                int a = que.front().first;   //idx
                int b = que.front().second;  //value
                m = max(m , b);
                que.pop();
                que.push(make_pair(a,b));
            }
            if(que.front().second != m)
            {
                int a = que.front().first;
                int b = que.front().second;
                que.pop();
                que.push(make_pair(a,b));
            }
            else
            {
                if(que.front().first == idx)
                {
                    cout <<cnt<<endl;
                    break;
                }
                else
                {
                    que.pop();
                    cnt++;
                }
            }
        }
        
        c--;
    }
    return 0;
}