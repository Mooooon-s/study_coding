#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;

    cin >> n;

    long long int low = n;

    long long int hight = n*2;

    long long int top = n;

    long long int result = low + hight + top;
    
    cout << result;

    return 0;
}