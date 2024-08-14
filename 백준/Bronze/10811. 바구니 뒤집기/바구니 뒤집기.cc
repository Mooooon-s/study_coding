#include <bits/stdc++.h>

using namespace std;

#define MAX 101

int buket[MAX];

int main(void){
    int n , m ;
    cin >> n >> m;

    for(int i=0;i<=n;i++){
        buket[i]=i;
    }
    
    for(int i=0;i<m;i++){
        int a ,b ;
        cin >> a >> b;
        int count = (b-a);

        if(count%2 !=0)
            count +=1;

        // cout << count << '\n';
        
        for(int i=0;i<count/2;i++){
            // cout << a+i << ' ' << b-i << "\n";
            int tmp= buket[a+i];
            buket[a+i] = buket[b-i];
            buket[b-i]= tmp;
        }
    }

    for(int i=1;i<=n;i++){
        cout << buket[i] << ' ';
    }
    
    return 0;
}