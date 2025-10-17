#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

using ll = int64_t;

int32_t main() {
	optimizar_io
	int N, T;

	while (cin >> N >> T, N && T) {
		vector<int> b(N);
		for (int &x : b) cin >> x;
		vector<vector<int>> ady(N + 1, vector<int>());
		for (int i = 0; i < N; i++) {
			ady[b[i]].push_back(i + 1);
		}
		/*for (int i = 0; i < ady.size(); i++) {
			cout << i << " : ";
			for (int u : ady[i])
				cout << u << " ";
			cout << '\n';
		}*/
		function<int(int)> dfs = [&](int u) -> int {
			if (ady[u].empty()) return 1;
			int k = ady[u].size();
			vector<int> costos;
			for (int v : ady[u]) {
				costos.push_back(dfs(v));
			}
			sort(costos.begin(), costos.end());
			int need = (T * k + 99) / 100;
			int sum = 0;
			for (int i = 0; i < need; i++) sum += costos[i];
			return sum;
		};
		cout << dfs(0) << '\n';
	}
	return 0;
}
