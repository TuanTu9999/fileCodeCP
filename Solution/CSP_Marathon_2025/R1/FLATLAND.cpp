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

#define maxn ((int)(1e6) + 100000)
#define LOG (int)(31 - __builtin_clz(maxn))
const int lim = 1e6 + 10000;
// #define ONLINE_JUDGE

int n, m, s, t;
bool isPrime[maxn];
vector<int> prime;
vector<pii> adj[maxn];

long long dist[maxn];

void dijsktra(int u) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.emplace(0, u);
	dist[u] = 0;

	while (pq.size()) {
		u = pq.top().second;
		long long cost = pq.top().first;
		pq.pop();

		if (cost > dist[u]) continue;

		for (const auto &[v, w] : adj[u]) if (dist[v] > dist[u] + w) {
			dist[v] = dist[u] + w;
			pq.emplace(dist[v], v);
		}
	}
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "FLATLAND"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    for (int i = 2; i * i <= lim; i++) if (!isPrime[i]) {
    	for (int j = i * i; j <= lim; j += i) {
    		isPrime[j] = 1;
    	}
    }
    for (int i = 2; i <= lim; i++) if (!isPrime[i]) prime.emplace_back(i);

    cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++) {
		int x, y, w; cin >> x >> y >> w;
		int val = *lower_bound(all(prime), w) - w;
		int pos = upper_bound(all(prime), w) - prime.begin() - 1;
		if (pos) minimize(val, w - prime[pos]);
		adj[x].emplace_back(y, val);
		adj[y].emplace_back(x, val);
	}

	for (int i = 0; i <= n; i++) dist[i] = 1e18;
	dijsktra(s);

	cout << dist[t];

    return 0;
}