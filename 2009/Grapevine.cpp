#include <bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(false);cin.tie(0);

using ll = int64_t;

int32_t main() {
	optimizar_io
	int n, m, Q, L, U;

	while (cin >> n >> m, (n && m)) {
		vector<vector<int>> h(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cin >> h[i][j];
		}
		cin >> Q;
		while (Q--) { // O(Q * log(min(N, M)) * NlogM)
			cin >> L >> U;
			int low = 1, hig = min(n, m) + 1;
			while (low < hig) {
				int mid = (low + hig) / 2;
				auto check = [&](int k) -> bool {
					for (int i = 0; i + k - 1 < n; i++) {
		                int j = lower_bound(h[i].begin(), h[i].end(), L) - h[i].begin();
		                if (j + k - 1 < m) {
		                	int minVal = h[i][j];
			                int maxVal = h[i + k - 1][j + k - 1];
			                if (L <= minVal and maxVal <= U)
			                	return true;
		                }
		            }
			        return false;
				};
				if (not check(mid))
					hig = mid;
				else
					low = mid + 1;
			}
			cout << low - 1 << '\n';
		}
		cout << "-\n";
 	}
	return 0;
}
