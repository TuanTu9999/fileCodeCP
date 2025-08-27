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

#define maxn ((int)(1e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, q, a[maxn];
vector<int> adj[maxn];

int heavy[maxn], par[maxn], high[maxn];
int tin[maxn], tout[maxn], flat[maxn], head[maxn], timeHLD;

int tree[maxn << 2];
int lazy[maxn << 2];

void build(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[flat[l]];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);

	tree[id] = tree[id << 1] ^ tree[id << 1 | 1];
}

void Push(int id, int l, int r) {
	if (lazy[id] == 0) return;

	int mid = l + r >> 1;

	if ((mid - l + 1) & 1) 
		tree[id << 1] ^= lazy[id];
	lazy[id << 1] ^= lazy[id];

	if ((r - mid) & 1)
		tree[id << 1 | 1] ^= lazy[id];
	lazy[id << 1 | 1] ^= lazy[id];

	lazy[id] = 0;
}

void update(int st, int en, int val, int id = 1, int l = 1, int r = n) {
	if (en < l || r < st) return;
	if (st <= l && r <= en) {
		if ((r - l + 1) & 1)
			tree[id] ^= val;
		lazy[id] ^= val;
		return;
	}
	Push(id, l, r);
	int mid = l + r >> 1;
	update(st, en, val, id << 1, l, mid);
	update(st, en, val, id << 1 | 1, mid + 1, r);

	tree[id] = tree[id << 1] ^ tree[id << 1 | 1];
}

int get(int st, int en, int id = 1, int l = 1, int r = n) {
	if (en < l || r < st) return 0;
	if (st <= l && r <= en) return tree[id];
	Push(id, l, r);
	int mid = l + r >> 1;
	return get(st, en, id << 1, l, mid) ^
		   get(st, en, id << 1 | 1, mid + 1, r);
}

int dfs(int u, int p) {
	int Sz = 1, maxSz = -1;
	for (int v : adj[u]) if (v ^ p) {
		par[v] = u;
		high[v] = high[u] + 1;
		int subSz = dfs(v, u);
		if (maximize(maxSz, subSz)) {
			heavy[u] = v;
		}
		Sz += subSz;
	}
	return Sz;
} 

void hld(int u, int h) {
	head[u] = h;
	tin[u] = ++timeHLD;
	flat[timeHLD] = u;

	if (heavy[u]) hld(heavy[u], h);
	for (int v : adj[u]) if (v != par[u] && v != heavy[u]) {
		hld(v, v);
	}

	tout[u] = timeHLD;
}

int getPath(int x, int y) {
	int res = 0;
	while (head[x] != head[y]) {
		if (high[head[x]] < high[head[y]])
			swap(x, y);
		res ^= get(tin[head[x]], tin[x]);
		x = par[head[x]];
	}
	if (high[x] < high[y]) 
		swap(x, y);
	res ^= get(tin[y], tin[x]);
	return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "BAI2"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
    	int x, y; 
    	cin >> x >> y;
    	adj[x].emplace_back(y);
    	adj[y].emplace_back(x);
    }

    dfs(1, 0);
    hld(1, 1);
    build(1, 1, n);

	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) {
			update(tin[x], tout[x], y);
		} else {
			cout << getPath(x, y) << '\n';
		}
	}

    return 0;
}
