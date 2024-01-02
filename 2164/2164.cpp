#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    queue<int> a;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        a.push(i);
    }

    //제일 위에 있는걸 뺌
    //제일 위에 있는걸 아래로

    while (a.size() != 1)
    {
        a.pop();

        if (a.size() == 1)
            break;

        a.push(a.front());
        a.pop();
    }

    cout << a.front();
}