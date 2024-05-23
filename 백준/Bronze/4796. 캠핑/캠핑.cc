#include <iostream>

using namespace std;

int main() {
    int P,L,V;

    int cnt=0;
    while(1)
        {
            cnt++;
            cin >> L >> P >> V;
            if(P+L+V == 0)
                break;

            int temp=0;
            int tempA =0;
            int tempB =0;
            tempA = (V/P)*L;
            tempB = (V%P);
            if(tempB > L)
                tempB = L;

            temp = tempA+ tempB;
            
            cout << "Case "<<cnt <<": " << temp << '\n';
        }
    
    return 0;
}