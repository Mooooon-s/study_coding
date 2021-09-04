#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    int n=0;
    n=a.size();
    for(int i=0;i<n;i++){
        ans+=a[i];
    }

	return ans;
}
