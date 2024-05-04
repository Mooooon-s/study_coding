#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cur =0;

void debug(int a)
{
        for(int i=7;i>=0;i--)
        {
            int temp = (a >> i) & 1;
            cout << temp;
        }
    cout << endl;
}

void ADD()
{
    int num;
    cin >> num;
    cur = cur | (1 << num);
    //cout << "add ";
    //debug(cur);
}

void REMOVE()
{
    int num;
    cin >> num;
    cur = cur & ~(1 << num);
    //cout << "remove ";
    //debug(cur);
}

void CHECK()
{
    int num;
    cin >>num;
    if(cur & (1 << num))
        cout << 1 <<'\n';
    else
        cout << 0 << '\n';
}

void TOGGLE()
{
    int num;
    cin >> num;
    cur = cur ^ (1 << num);
    //cout << "toggle ";
    //debug(cur);
}

void ALL()
{
    //cur = 20971501;
    for(int i=1;i<=20;i++)
        {
            cur = cur | (1 << i);
        }
    //cout << cur;
    //cout << "all ";
    //debug(cur);
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int m;
    cin >> m;

    
    for(int i=0;i<m;i++)
        {
            string cmd;
            cin >> cmd;
            if(cmd == "add")
                ADD();
            else if(cmd == "remove")
                REMOVE();
            else if(cmd == "check")
                CHECK();
            else if(cmd == "toggle")
                TOGGLE();
            else if(cmd == "all")
                ALL();
            else if(cmd == "empty")
                cur =0;
        }
    
    return 0;
}