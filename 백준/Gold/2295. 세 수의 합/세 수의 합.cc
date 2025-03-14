#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> sum;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            sum.push_back(arr[i]+arr[j]);
        }
    }

    sort(sum.begin(),sum.end());
    sort(arr,arr+n);
    
    int r=-1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            int a = 0;
            int b = sum.size()-1;

            while(a<=b){
                int mid = (a+b)/2;
                //cout << sum[mid] << '\n';
                if(sum[mid]==arr[i]-arr[j]){
                    r = max(r,sum[mid]+arr[j]);
                }
                if(arr[i]-arr[j] > sum[mid]) a=mid+1;
                else b = mid-1;
            }
        }
    }

    cout << r;

    return 0;
}