#include <bits/stdc++.h>
// https://drive.google.com/file/d/1TYY25TkNo_TzenTjwbl9CZJEitaLI8x-/view?usp=drive_link

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

#define maxn ((int)(3e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, l, q, Ans[maxn];
pii a[maxn];
vector<pii> qu[maxn];

struct Node {
    int Max, Min;
};
struct Segtri {
    Node tree[maxn << 2];
    int lazy[maxn << 2];

    inline void init(int n) {
        for (int i = 1; i <= (n << 2); i++) {
            tree[i].Max = 0;
            tree[i].Min = 0;
            lazy[i] = 0;
        }
    }

    inline Node merge(const Node &a, const Node &b) {
        int Min = min(a.Min, b.Min);
        int Max = max(a.Max, b.Max);
        return {Max, Min};
    }

    inline void add(int id, int val, int l, int r) {
        lazy[id] += val;
        tree[id].Min += val;
        tree[id].Max += val;
    }

    void Push(int id, int l, int r) {
        if (lazy[id] == 0) return;
        int mid = l + r >> 1;

        add(id << 1, lazy[id], l, mid);
        add(id << 1 | 1, lazy[id], mid + 1, r);

        lazy[id] = 0;
    }

    void updateProcess(int st, int en, int val, int id, int l, int r) {
        if (r < st || en < l) return;
        if (st <= l && r <= en) {
            add(id, val, l, r);
            return;
        }
        Push(id, l, r);
        int mid = l + r >> 1;
        updateProcess(st, en, val, id << 1, l, mid);
        updateProcess(st, en, val, id << 1 | 1, mid + 1, r);

        tree[id] = merge(tree[id << 1], tree[id << 1 | 1]);
    }

    Node getProcess(int st, int en, int id, int l, int r) {
        if (r < st || en < l) return {0, (int)1e9};
        if (st <= l && r <= en) return tree[id];
        Push(id, l, r);
        int mid = l + r >> 1;
        return merge(getProcess(st, en, id << 1, l, mid),
                     getProcess(st, en, id << 1 | 1, mid + 1, r));
    }

    void update(int st, int en, int val) {
        updateProcess(st, en, val, 1, 1, n);
    }
    Node get(int st, int en) {
        return getProcess(st, en, 1, 1, n);
    }
} it;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> l >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[i] = {x, i};
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) cout << a[i].first << ' ';
    cout << '\n';

    it.init(n);

    for (int i = 1; i <= n; i++) {
        int val = a[i].first;
        int pos = a[i].second;
        it.update(max(l, pos), min(n, pos + l - 1), 1);
        Node res = it.get(max(l, pos), min(n, pos + l - 1));
        int Qmin = res.Min, Qmax = res.Max;

        // cerr << Qmin << ' ' << Qmax << '\n';
        qu[Qmin].emplace_back(val, 1);
        qu[Qmax + 1].emplace_back(val, 0);
    }


    set<int> se;
    for (int i = 1; i <= l; i++) {
        for (const pii &ask : qu[i]) {
            if (ask.second == 1) {
                se.insert(ask.first);
            } else {
                se.erase(ask.first);
            }
        }

        Ans[i] = *se.rbegin();
    }

    // for (int i = 1; i <= l; i++) cout << Ans[i] << ' ';
    // cout << '\n';

    while (q--) {
        int x; cin >> x;
        cout << Ans[x] << ' ';
    }

    return 0;
}
