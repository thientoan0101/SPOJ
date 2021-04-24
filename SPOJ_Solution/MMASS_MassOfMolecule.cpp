#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;



int main()
{
	string s;
	getline(cin, s);

	stack<int> st;
	int m = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C') {
			st.push(12);
		}
		else if (s[i] == 'H') {
			st.push(1);
		}
		else if (s[i] == 'O') {
			st.push(16);
		}
		else if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] >= '0' && s[i] <= '9') {
			int temp = st.top();
			st.pop();
			st.push(temp * (int)(s[i] - 48));
		}
		else if (s[i] == ')') {
			int temp = 0;
			while (st.top() != '(') {				
				temp = temp + st.top();
				st.pop();
			}
			st.pop();
			st.push(temp);
		}
	}
	while (!st.empty()) {
		m = m + st.top();
		st.pop();
	}	
	cout << m;
	return 0;
}