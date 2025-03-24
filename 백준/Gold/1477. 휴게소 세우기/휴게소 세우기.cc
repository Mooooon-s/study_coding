#include <bits/stdc++.h>

using namespace std;

int main(){
    int n , m,d;
    cin >> n >> m >> d;

    vector<int> v;

    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    v.push_back(0);
    v.push_back(d);
    sort(v.begin(),v.end());

    int a = 1;
    int b = d-1;

    int r =123456789;
    while(a<=b){
        int mid = (a+b)/2;

        int cnt=0;
        for(int i=0;i<v.size()-1;i++){
            int L = v[i+1] - v[i];
            int c = L / mid;

            if(c > 0){
                if(L % mid == 0) c--;
    
                cnt += c;
            }
        }

        if(cnt > m){
            a = mid+1;
        }
        else{
            b = mid -1;
            r = min(r,mid);
        }
    }

    cout << r;

    return 0;
}