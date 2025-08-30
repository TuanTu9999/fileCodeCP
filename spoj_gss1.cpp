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

#define maxn ((int)(5e4) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, a[maxn];

struct Node {
	long long Max, pre, suf, sum;
	Node() {
		Max = pre = suf = sum = 0;
	}
	void operator = (const int &val) {
		Max = pre = suf = sum = val;
	}
	Node operator + (const Node &R) {
		Node res;
		Node L = *this;

		res.Max = max({L.Max, R.Max, L.pre, R.suf, L.suf + R.pre, L.sum + R.pre, L.suf + R.sum});
		res.pre = max(L.pre, L.sum + R.pre);
		res.suf = max(R.suf, L.suf + R.sum);
		res.sum = L.sum + R.sum;

		return res;
	}
} tree[maxn << 2];

void build(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);

	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

void update(int pos, int val, int id = 1, int l = 1, int r = n) {
	if (pos < l || r < pos) return;
	if (l == r) {
		tree[id] = val;
		return;
	}
	int mid = l + r >> 1;
	update(pos, val, id << 1, l, mid);
	update(pos, val, id << 1 | 1, mid + 1, r);

	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

Node get(int st, int en, int id = 1, int l = 1, int r = n) {
    if (en < l || r < st) {
        Node res;
        res.sum = 0;
        res.pre = res.suf = res.Max = -1e18;
        return res;
    }
    if (st <= l && r <= en) return tree[id];
    int mid = l + r >> 1;
    Node left = get(st, en, id << 1, l, mid);
    Node right = get(st, en, id << 1 | 1, mid + 1, r);
    return left + right;
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
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

	int tt;
	cin >> tt;
	while (tt--) {
		int x, y;
		cin >> x >> y;
		cout << get(x, y).Max << '\n';
	}

    return 0;
}
