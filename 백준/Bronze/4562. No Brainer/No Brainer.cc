#include <iostream>

using namespace std;

int main() {
    int t,x,y;
    cin >>t;
    for(int i=0;i<t;i++){
        cin >> x >> y;
        if(x < y)
            cout << "NO BRAINS\n";
        else
            cout << "MMM BRAINS\n";
    }
    return 0;
}