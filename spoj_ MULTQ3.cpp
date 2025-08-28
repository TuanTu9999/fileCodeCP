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

int n, q;

struct Node {
	int cnt[3];
	int lazy;

	Node operator + (const Node &o) {
		Node res;
		for (int i = 0; i < 3; i++) {
			res.cnt[i] = cnt[i] + o.cnt[i];
		}
		return res;
	}

	Node operator + (const int &val) {
		Node res = *this;
		res.lazy += val;
		int nCnt[3];
		memset(nCnt, 0, sizeof nCnt);
		for (int i = 0; i < 3; i++) {
			nCnt[(i + val) % 3] = cnt[i];
		}
		memcpy(res.cnt, nCnt, sizeof nCnt);
		return res;
	}
} tree[maxn << 2];

void Push(int id) {
	if (tree[id].lazy == 0) return;

	tree[id << 1] = tree[id << 1] + tree[id].lazy;
	tree[id << 1 | 1] = tree[id << 1 | 1] + tree[id].lazy;

	tree[id].lazy = 0;
}

void build(int id, int l, int r) {
	if (l == r) {
		tree[id].cnt[0] = 1;
		tree[id].cnt[1] = tree[id].cnt[2] = tree[id].lazy = 0;
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);

	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

void update(int st, int en, int id = 1, int l = 1, int r = n) {
	if (en < l || r < st) return;
	if (st <= l && r <= en) {
		tree[id] = tree[id] + 1;
		return;
	}
	Push(id);
	int mid = l + r >> 1;
	update(st, en, id << 1, l, mid);
	update(st, en, id << 1 | 1, mid + 1, r);

	tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int get(int st, int en, int id = 1, int l = 1, int r = n) {
	if (en < l || r < st) return 0;
	if (st <= l && r <= en) return tree[id].cnt[0];

	Push(id);
	int mid = l + r >> 1;
	return get(st, en, id << 1, l, mid) + 
		   get(st, en, id << 1 | 1, mid + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> q;

    build(1, 1, n);

    while (q--) {
    	int type, l, r;
    	cin >> type >> l >> r;
    	++l; ++r;

    	if (type == 0) {
    		update(l, r);
    	} else {
    		cout << get(l, r) << '\n';
    	}
    }

    return 0;
}
