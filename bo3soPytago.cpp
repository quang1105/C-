#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		long long a[n];
		string ans = "NO";
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				long long k = a[i] * a[i] + a[j] * a[j];
				long long x = sqrt(k);
				if(x * x == k && binary_search(a + j + 1, a + n, x)) {
					ans = "YES";
					break;
				}
			}
			if(ans == "YES") {
				break;
			}
		}
		cout << ans << "\n";
	
	}
    return 0;
}

