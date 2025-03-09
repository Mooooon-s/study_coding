#include <bits/stdc++.h>
#define MAX 101


using namespace std;

int lightSwitch[MAX];

int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> lightSwitch[i];
    }

    int num;
    cin >> num;

    for(int i=0;i<num;i++){
        int g,idx;
        cin >> g >> idx;

        switch (g) {
            case 1:
                {
                    //cout << "male ";
                    for(int i=1;i<=n;i++){
                        if(idx*i > n) break;
                        else{
                            //cout << idx*i << ' ' << lightSwitch[idx*i] << ' ';
                            if(lightSwitch[idx*i]==1) lightSwitch[idx*i]=0;
                            else lightSwitch[idx*i]=1;

                            //cout << "after : " << lightSwitch[idx*i]<<'\n';
                        }
                    }
                    break;
                }
            case 2:
                {
                    //cout << "female ";
                    int i_MIN=idx;
                    int i_MAX=idx;
                    for(int i=1;i<=n;i++){
                        int a = idx-i;
                        int b = idx+i;
                        if(a <= 0 || b > n) break;
                        if(lightSwitch[a]!=lightSwitch[b])break;
                        if(lightSwitch[a]==lightSwitch[b]){
                            i_MIN = a;
                            i_MAX = b;                        }
                    }

                    for(int i=i_MIN;i<=i_MAX;i++){
                        if(lightSwitch[i]==1) lightSwitch[i]=0;
                        else lightSwitch[i]=1;
                    }
                    
                    break;
                }
                
        }
    }

    for(int i=1;i<=n;i++){
        cout<<lightSwitch[i]<<' ';
        if(i%20==0) cout << '\n';
    }

    return 0;
}