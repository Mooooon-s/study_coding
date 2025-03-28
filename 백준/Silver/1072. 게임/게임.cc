#include <bits/stdc++.h>

using namespace std;

int main(){
    long long x , y;
    cin >> x >> y;

    long long z = (y*100)/x;

    if(z>=99){
        cout << -1;
        return 0;
    }

    long long a = 0;
    long long b = 1000000000;

    while(a<=b){
        long long mid = (a+b)/2;

        long long tmp = (y+mid)*100 / (x+mid);


        if(z<tmp){
            b = mid -1;
        }
        else{
            a = mid +1;
        }
    }

    cout << a;

    return 0;
}