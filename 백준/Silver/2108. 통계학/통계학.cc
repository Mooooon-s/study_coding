#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >>n;

    vector<int> v;
    int mode[8001] = {0,};

    
    double sum=0;
    int max = -9999;
    int max_second = 0;
    
    for(int i=0;i<n;i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
            
            sum +=tmp;
            
            mode[tmp+4000]++;
            if(mode[tmp+4000] > max)
                max = mode[tmp+4000];
        }
    
    sort(v.begin(),v.end());

    if ((sum / n) > 0)
	{
		cout << (int)((sum / n) + 0.5) << "\n";
	}
	else {
		cout << (int)((sum / n) - 0.5) << "\n";
	}
    
    cout << v[n/2]<<'\n';

    if(v.size() > 1)
    {
        vector<int> modes;
        for(int i=0;i<8001;i++)
            {
                if(mode[i] == max)
                    modes.push_back(i-4000);
            }
        if(modes.size()==1)
            cout << modes[0] << '\n';
        else if(modes.size()==2)
        {
            sort(modes.begin(), modes.end());
			if (modes[0] < modes[1])
			{
				cout << modes[1] << "\n";
			}
			else cout << modes[0] << "\n";
        }
        else
        {
            cout << modes[1] << "\n";
        }
    }
    else
        cout << v.back()<<'\n';

    if(v.size()>1)
        cout << v.back()-v.front();
    else
        cout << 0;
    
    return 0;
}