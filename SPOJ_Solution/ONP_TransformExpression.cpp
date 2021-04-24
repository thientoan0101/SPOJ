#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;


int main()
{
	int T;
	stack<int> st;
	cin >> T;
	cin.ignore(1);
	vector<string> express(T);
	vector<string> res(T);

	for (int i = 0; i < T; i++) {
		getline(cin, express[i]);
		//cin >> express[i];
	}

	

	int stt = 0;

	for (auto s : express) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				res[stt].push_back(s[i]);
			}
			else if (s[i] == '+' && s[i] == '-' && s[i] == '*' && s[i] == '/' && s[i] == '^' && s[i]=='(') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				while (st.size() != 0 && st.top() != '(') {
					char temp = st.top();
					st.pop();
					res[stt].push_back(temp);
				}
				if (st.top() == '(') st.pop();
			}
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}
	cout << "fgsdgsd";
	return 0;
}