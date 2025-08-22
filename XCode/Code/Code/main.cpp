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

int n, q, a[maxn], sq, Ans[maxn];
int comp[maxn];
struct Query {
    int l, r, id;
} qu[maxn * 5];

int curL = 1, curR;
multiset<int> ms;

void MO(int l, int r) {
    while (l < curL) {
        --curL;
        
    }
    while (curR < r) {
        ++curR;
        
    }
    while (curL < l) {
        dq.pop_back();
        ++curL;
    }
    while (curR > r) {
        dq.pop_front();
        --curR;
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
        cin >> a[i];
        comp[++comp[0]] = a[i];
    }

    sort(comp + 1, comp + comp[0] + 1);
    comp[0] = unique(comp + 1, comp + comp[0] + 1) - comp - 1;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(comp + 1, comp + comp[0] + 1) - comp;
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
    }

    sq = sqrt(n);
    sort(qu + 1, qu + q + 1, [&](const pii &x, const pii &y) {
        if (x.l / sq == y.l / sq) return x.r < y.r;
        return x.l < y.l;
    });



    return 0;
}
