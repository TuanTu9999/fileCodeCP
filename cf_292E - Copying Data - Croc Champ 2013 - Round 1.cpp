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

int n, m;
int a[maxn], b[maxn];

pii tree[maxn << 2], lazy[maxn << 2];

void Push(int id) {
    if (lazy[id].second == 0) return;
    for (int i = (id << 1); i <= (id << 1 | 1); i++) {
        tree[i].first = lazy[id].first;
        lazy[i].first = lazy[id].first;

        tree[i].second = 1;
        lazy[i].second = 1;
    }

    lazy[id] = {0, 0};
}

void update(int st, int en, int val, int id = 1, int l = 1, int r = n) {
    if (en < l || r < st) return;
    if (st <= l && r <= en) {
        tree[id].first = val;
        lazy[id].first = val;

        tree[id].second = 1;
        lazy[id].second = 1;
        return;
    }
    Push(id);
    int mid = l + r >> 1;
    update(st, en, val, id << 1, l, mid);
    update(st, en, val, id << 1 | 1, mid + 1, r);
}

pii get(int pos, int id = 1, int l = 1, int r = n) {
    if (l == r) return tree[id];
    Push(id);
    int mid = l + r >> 1;
    if (pos <= mid) return get(pos, id << 1, l, mid);
    return get(pos, id << 1 | 1, mid + 1, r);
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
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int cnt = 0;
    while (m--) {
        ++cnt;
        int type; 
        cin >> type;
        if (type == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            update(y, y + k - 1, x - y);
        } else {
            int x;
            cin >> x;
            pii res = get(x);
            // cerr << cnt << ' ' << x << ' ' << res.first << ' ' << res.second << '\n';

            if (res.second == 1)
                cout << a[x + res.first] << '\n';
            else 
                cout << b[x] << '\n';
        }
    }

    return 0;
}
