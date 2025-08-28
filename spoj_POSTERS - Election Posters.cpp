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

#define maxn ((int)80010)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, comp[maxn];
pii qu[maxn];

int tree[maxn << 2], lazy[maxn << 2];

void Push(int id) {
	if (lazy[id] == -1) return;

	for (int i = (id << 1); i <= (id << 1 | 1); i++) {
		tree[i] = lazy[i] = lazy[id];
	}

	lazy[id] = -1;
}

void update(int st, int en, int val, int id = 1, int l = 1, int r = comp[0]) {
	if (en < l || r < st) return;
	if (st <= l && r <= en) {
		tree[id] = lazy[id] = val;
		return;
	}
	Push(id);
	int mid = l + r >> 1;

	update(st, en, val, id << 1, l, mid);
	update(st, en, val, id << 1 | 1, mid + 1, r);
}

int get(int pos, int id = 1, int l = 1, int r = comp[0]) {
	if (l == r) return tree[id];
	Push(id);

	int mid = l + r >> 1;

	if (pos <= mid)
		return get(pos, id << 1, l, mid);
	return get(pos, id << 1 | 1, mid + 1, r);
}

void process() {
	cin >> n;
	comp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		qu[i] = {l, r};
		comp[++comp[0]] = l;
		comp[++comp[0]] = r;
	}

	sort(comp + 1, comp + comp[0] + 1);
	comp[0] = unique(comp + 1, comp + comp[0] + 1) - comp - 1;

	memset(lazy, -1, (comp[0] << 2) * sizeof(int));

	for (int i = 1; i <= n; i++) {
		int l = lower_bound(comp + 1, comp + comp[0] + 1, qu[i].first) - comp;
		int r = lower_bound(comp + 1, comp + comp[0] + 1, qu[i].second) - comp;

		update(l, r, i);
	}

	set<int> se;

	for (int i = 1; i <= comp[0]; i++) 
		se.insert(get(i));

	cout << se.size() << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int tt;
    cin >> tt;
    while (tt--) {
    	process();
    }

    return 0;
}
