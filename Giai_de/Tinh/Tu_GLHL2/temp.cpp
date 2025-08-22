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

#define maxn ((int)(1e6) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, Ans[maxn];
vector<int> adj[maxn];

int high[maxn], heavy[maxn];
int timeDFS, tin[maxn], tout[maxn], flat[maxn];
int dfs(int u, int p) {
	tin[u] = ++timeDFS;
	flat[timeDFS] = u;
	int Sz = 1, maxSz = -1;

	for (int v : adj[u]) if (v ^ p) {
		high[v] = high[u] + 1;
		int subSz = dfs(v, u);
		if (maximize(maxSz, subSz)) {
			heavy[u] = v;
		}
		Sz += subSz;
	}

	tout[u] = timeDFS;
	return Sz;
}

int cnt[maxn], best = 1e9, maxCnt;
inline void add(int u) {
	cnt[high[u]]++;
	if (cnt[high[u]] > maxCnt) {
		maxCnt = cnt[high[u]];
		best = high[u];
	} else if (cnt[high[u]] == maxCnt && best > high[u]) {
		best = high[u];
	}
}

void dsu(int u, int p, bool keep) {
	for (int v : adj[u]) if (v != p && v != heavy[u]) {
		dsu(v, u, 0);
	}
	if (heavy[u]) dsu(heavy[u], u, 1);

	for (int v : adj[u]) if (v != p && v != heavy[u]) {
		for (int i = tin[v]; i <= tout[v]; i++) {
			add(flat[i]);
		}
	}
	add(u);

	Ans[u] = best - high[u];

	if (keep == 0) {
		for (int i = tin[u]; i <= tout[u]; i++) {
			cnt[high[flat[i]]]--;
		}
		best = 1e9;
		maxCnt = 0;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i < n; i++) {
    	int x, y; cin >> x >> y;
    	adj[x].emplace_back(y);
    	adj[y].emplace_back(x);
    }

    dfs(1, 0);
    dsu(1, 0, 1);

    for (int i = 1; i <= n; i++) cout << Ans[i] << '\n';

    return 0;
}