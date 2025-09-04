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

#define maxn ((int)(2e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n;
bool color[maxn];
vector<int> adj[maxn];

int tree[maxn << 2], lazy[maxn << 2];

void Push(int id) {
	if (lazy[id] == (int)-1e9) return;
	for (int i = id << 1; i <= (id << 1 | 1); i++) {
		maximize(tree[i], lazy[id]);
		maximize(lazy[i], lazy[id]);
	}

	lazy[id] = (int)-1e9;
}

void update(int st, int en, int val, int id = 1, int l = 1, int r = n) {
	if (en < l || r < st) return;
	if (st <= l && r <= en) {
		maximize(tree[id], val);
		maximize(lazy[id], val);
		return;
	}
	Push(id);
	int mid = l + r >> 1;

	update(st, en, val, id << 1, l, mid);
	update(st, en, val, id << 1 | 1, mid + 1, r);

	tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}

int get(int pos, int id = 1, int l = 1, int r = n) {
	if (pos < l || r < pos) return -1e9;
	if (l == r) return tree[id];
	Push(id);
	int mid = l + r >> 1;
	return max(get(pos, id << 1, l, mid),
			   get(pos, id << 1 | 1, mid + 1, r));
}


int dpin[maxn], dpout[maxn];

void dfsin(int u, int p) {
	int sum = 0;
	for (int v : adj[u]) if (v ^ p) {
		dfsin(v, u);
		if (dpin[v] > 0) sum += dpin[v];
	}

	dpin[u] = sum + (color[u] ? -1 : 1);
}

void dfsout(int u, int p) {
	int sum = 0;

	for (int v : adj[u]) if (v ^ p) {
		if (dpin[v] > 0) sum += dpin[v];
	}

	for (int v : adj[u]) if (v ^ p) {
		int w = sum + (color[u] ? -1 : 1);
		if (dpin[v] > 0) w -= dpin[v];
		maximize(dpout[v], dpout[u] + w);

		dfsout(v, u);
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
    for (int i = 1; i <= n; i++) {
    	char x; cin >> x;
    	color[i] = x == '0';
    }
    for (int i = 1; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	adj[x].emplace_back(y);
    	adj[y].emplace_back(x);
    }

    dfsin(1, 1);
    dfsout(1, 1);

    // for (int i = 1; i <= n; i++)
    // 	cout << dpin[i] << ' ';
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // 	cout << dpout[i] << ' ';
    // cout << '\n';

	for (int i = 1; i <= n; i++) {
		cout << dpin[i] + dpout[i] << ' ';
	}    

    return 0;
}
