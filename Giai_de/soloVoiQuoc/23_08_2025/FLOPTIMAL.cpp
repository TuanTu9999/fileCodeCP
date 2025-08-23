#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define COMP(x) x.resize(unique(all(x)) - x.begin())
template<typename T>
inline bool maximize(T &res, const T &val) {
    if (res < val) return res = val, 1;
    return 0;
}
template<typename T>
inline bool minimize(T &res, const T &val) {
    if (res > val) return res = val, 1;
    return 0;
}

using namespace std;

#define maxn 11
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, m;
vector<pii> adj[maxn];
long long dp[maxn][1 << 11], cost[maxn][maxn];
int trace[maxn][1 << 11];

void dijktra(int st) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, st});
	cost[st][st] = 0;
	while (pq.size()) {
		int u = pq.top().second;
		long long w = pq.top().first;
		pq.pop();

		if (w > cost[st][u]) continue;

		for (const auto &[v, w] : adj[u]) if (cost[st][v] > cost[st][u] + w) {
			cost[st][v] = cost[st][u] + w;
			pq.push({cost[st][v], v});
		}
	}
}

inline string bin(int mask) {
	string s = "";
	for (int i = 3; i >= 0; i--) {
		if (mask & (1 << i)) s += '1';
		else s += '0';
	}
	return s;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> m;
	int fullmask = (1 << n) - 1;

	for (int i = 1; i <= m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		--x; --y;
		adj[x].emplace_back(y, w);
		adj[y].emplace_back(x, w);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cost[i][j] = 1e18;
		for (int j = i + 1; j < n; j++) {
			adj[i].emplace_back(j, 1e9);
			adj[j].emplace_back(i, 1e9);
		}
	}

	for (int i = 0; i < n; i++)
		dijktra(i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= fullmask; j++) {
			dp[i][j] = 1e18;
			trace[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++)
		dp[i][1 << i] = 0;

	for (int mask = 1; mask <= fullmask; mask++) {
		for (int u = 0; u < n; u++) if (mask & (1 << u)) {
			int premask = mask ^ (1 << u);
			for (int v = 0; v < n; v++) if (u != v && (premask & (1 << v))) {
				if (minimize(dp[u][mask], dp[v][premask] + cost[u][v])) {
					trace[u][premask] = v;
				}
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j <= fullmask; j++) {
	// 		cout << i << ' ' << bin(j) << ' ' << dp[i][j] << '\n';
	// 	}
	// }

	long long minPath = 1e18;
	int pos = n - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (minimize(minPath, dp[i][fullmask])) {
			pos = i;
		}
	}

	vector<int> Path;
	int mask = fullmask;
	while (pos >= 0) {
		Path.emplace_back(pos);
		mask ^= (1 << pos);
		pos = trace[pos][mask];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cost[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int x : Path) cout << x + 1 << ' ';
	cout << '\n';

	cout << minPath;

    return 0;
}