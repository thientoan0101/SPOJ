#include <iostream>
#include <stack>>
#include <vector>
#include <algorithm>
using namespace std;


int main() 
{
	int n;
	while (cin >> n) {
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<int> b(a);
		int k = 0;
		sort(b.begin(), b.end());
		stack<int> st;
		for (int i = 0; i < n; i++) {			
			while (st.size() != 0 && st.top() == b[k]) {
				k++;
				st.pop();
			}
			if (a[i] == b[k]) {
				k++;
			}
			else {
				st.push(a[i]);
			}
			
		}
		while (st.size() != 0) {
			if (st.top() != b[k]) {
				break;
			}
			else {
				k++;
				st.pop();
			}
		}
		if (k == n) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}


	return 0;
}