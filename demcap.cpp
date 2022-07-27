#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int count(int x, int y[], int n, int a[]){
	if(x == 0){
		return 0;
	}
	if(x == 1){
		return a[0];
	}
	int it = upper_bound(y, y + n, x) - y;
	int ans = n - it;
	ans += (a[0] + a[1]);
	if(x == 2){
		ans -= (a[3] + a[4]);
	}
	if(x == 3){
		ans += a[2];
	}
	return ans;
}
int main() {
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int x[n], y[m], a[5] ={}, s = 0;
		for(int i = 0; i < n; i++){
			cin >> x[i];
		}
		for(int i = 0; i < m; i++){
			cin >>y[i];
		}
		for(int i = 0; i < n; i++){
			if(y[i] < 5){
				a[y[i]]++;
			}
		}
		sort(y, y + n);
		for(int i = 0; i < m; i++){
			s += count(x[i], y, n, a);
		}
		cout << s << endl;
	}
    return 0;
}

