#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

using ll = int64_t;
const double eps = 1e-9;

vector<string> split(string &s) {
	stringstream ss(s);
	string w;
	vector<string> words;
	while (getline(ss, w, '/')) {
		words.push_back(w);
	}
	return words;
}

int32_t main() {
	optimizar_io
	string input;
	map<char,double> notes;

	notes['W'] = 1.0;
	notes['H'] = 0.5;
	notes['Q'] = 0.25;
	notes['E'] = 0.125;
	notes['S'] = 0.0625;
	notes['T'] = 0.03125;
	notes['X'] = 0.015625;

	while (getline(cin, input)) {
		if (input[0] == '*')
			break;
		vector<string> words = split(input);
		int ans = 0;
		for (string s : words) {
			double score = 0;
			for (char c : s) score += notes[c];
			if (fabs(score - 1.0) < eps)
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}
