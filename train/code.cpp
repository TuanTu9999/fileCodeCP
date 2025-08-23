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

#define maxn ((int)(3e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, m, a[maxn], b[maxn];
int comp[maxn << 1];

int tree[maxn << 4], lazy[maxn << 4];

void Push(int id) {
    if (lazy[id] == 0) return;
    tree[id << 1] += lazy[id];
    tree[id << 1 | 1] += lazy[id];
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
}

void update(int st, int en, int val, int id = 1, int l = 1, int r = n) {
    if (en < r || l < st) return;
    if (st <= l && r <= en) {
        tree[id] += val;
        lazy[id] += val;
        return;
    }
    Push(id);
    int mid = l + r >> 1;
    update(st, en, val, id << 1, l, mid);
    update(st, en, val, id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int get(int id = 1, int l = 1, int r = n) {
    if (l == r) return l;
    Push(id);
    int mid = l + r >> 1;

    int resR = get(id << 1 | 1, mid + 1, r);
    if (resR > 0) return resR;

    int resL = get(id << 1, l, mid);
    if (resL > 0) return resL;
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
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        comp[++comp[0]] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        comp[++comp[0]] = b[i];
    }

    sort(comp + 1, comp + comp[0] + 1);
    comp[0] = unique(comp + 1, comp + comp[0] + 1) - comp - 1;

    for (int i = 1; i <= m; i++) {
        b[i] = lower_bound(comp + 1, comp + comp[0] + 1, b[i]) - comp;
        update(1, b[i] - 1, -1);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(comp + 1, comp + comp[0] + 1, a[i]) - comp;
        update(1, a[i], 1);
    }

    int tt; cin >> tt;
    while (tt--) {
        int type; cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            y = lower_bound(comp + 1, comp + comp[0] + 1, y) - comp - 1;
            update(1, a[x], -1);
            update(1, y, 1);
            a[x] = y;
        } else {
            int x, y;
            cin >> x >> y;
            y = lower_bound(comp + 1, comp + comp[0] + 1, y) - comp - 1;
            update(1, b[x] - 1, 1);
            update(1, y, -1);
            b[x] = y;
        }
        cout << get() << '\n';
    }

    return 0;
}


