#include <bits/stdc++.h>
using namespace std;
bool Op(string s) {
	if(s == "+" || s == "-" || s == "*" || s == "/") {
		return 1;
	}
	return 0;
}
int so(string s) {
	int n = 0;
	for(int i = 0; i < s.size(); i++) {
		n = n * 10 + s[i] - '0';
	}
	return n;
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x, y, k;
		cin >> n;
		cin.ignore();
		string s, a;
		getline(cin, s);
		queue<int> st;
		for(int i = s.size() - 1; i >= 0; i--) {
			if(s[i] == ' ') {
				if(a.size() > 0) {
					st.push(so(a));
				}
				a = "";
				continue;
			}
			if(s[i] >= '0' && s[i] <= '9') {
				a = s[i] + a;
				continue;
			}
			x = st.front();
			st.pop();
			y = st.front();
			st.pop();
			if(s[i] == '*') {
				k = y * x;
			}
			if(s[i] == '/') {
				k = y / x;
			}
			if(s[i] == '+') {
				k = y + x;
			}
			if(s[i] == '-') {
				k = y - x;
			}
			st.push(k);
		}
		cout << st.front() << "\n";
	}
    return 0;
}
