#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c;

    cin >> a >> b >> c;

    if(a+b+c != 180)
        cout << "Error";
    else{        
        if( a== 0 || b== 0 || c == 0 || a == 180 || b == 180 || c == 180 )
            cout << "Error";
        else if(a == b && a == c)
            cout << "Equilateral";
        else if( a == b || a == c || b == c )
            cout << "Isosceles";
        else
            cout << "Scalene";
    }

    return 0;
}