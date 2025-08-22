#include <bits/stdc++.h>
#define debug(a) cerr << (a) << ' '
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define MASK(x) ((1LL) << (x))
#define BIT(x, i) (((x) >> (i)) & (1LL))
#define eb emplace_back
#define pb push_back

// #pragma GCC             optimize("Ofast")
// #pragma GCC             optimize("O3")
// #pragma GCC             optimize("unroll-loops")
// #pragma GCC             target("avx,avx2,fma")

using namespace std;

template<typename T>
bool maximize(T &res, const T &val) {
    if (res < val) {
        res = val;
        return 1;
    }
    return 0;
}

template<typename T>
bool minimize(T &res, const T &val) {
    if (res > val) {
        res = val;
        return 1;
    }
    return 0;
}

const int maxn = 5e5 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

int n, k, tt, a[maxn];
pii qu[maxn];

namespace sub1 {
    bool check() {
        return n <= 100;
    }

    bool dp[110][110];
    void process() {
        for (int i = 1; i < n; i++) if (a[i] + a[i + 1] == k) dp[i][i + 1] = 1;

        for (int len = 4; len <= n; len += 2) {
            for (int l = 1; l + len - 1 <= n; l++) {
                int r = l + len - 1;

                if (a[l] + a[r] == k && dp[l + 1][r - 1]) {
                    dp[l][r] = 1;
                }
                else {
                    for (int mid = l + 1; mid < r; mid++) if (dp[l][mid] && dp[mid + 1][r]) {
                        dp[l][r] = 1;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= tt; i++) {
            int l = qu[i].first;
            int r = qu[i].second;
            cout << (dp[l][r] ? "YES" : "NO");
            cout << '\n';
        }
    }
}

namespace sub2 {
    bool check() {
        return n <= (int)5e5 && tt <= 10;
    }

    void process() {
        for (int t = 1; t <= tt; t++) {
            vector<int> st;
            for (int i = qu[t].first; i <= qu[t].second; i++) {
                if (st.size() && a[st.back()] + a[i] == k) st.pop_back();
                else st.push_back(i);
            }

            if (st.size()) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}

namespace sub3 {
    int tree[maxn << 2], lazy[maxn << 2];

    void PUSH(int id) {
        if (lazy[id] == 0) return;
        tree[id << 1] = lazy[id];
        tree[id << 1 | 1] = lazy[id];
        lazy[id << 1] = lazy[id];
        lazy[id << 1 | 1] = lazy[id];

        lazy[id] = 0;
    }
    
    void update(int st, int en, int val, int id = 1, int l = 1, int r = n) {
        if (en < l || r < st) return;
        if (st <= l && r <= en) {
            lazy[id] = val;
            tree[id] = val;
            return;
        }
        int mid = l + r >> 1;
        PUSH(id);
        update(st, en, val, id << 1, l, mid);
        update(st, en, val, id << 1 | 1, mid + 1, r);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }

    int get(int st, int en, int id = 1, int l = 1, int r = n) {
        if (en < l || r < st) return inf;
        if (st <= l && r <= en) return tree[id];
        int mid = l + r >> 1;
        PUSH(id);
        return min(get(st, en, id << 1, l, mid),
                   get(st, en, id << 1 | 1, mid + 1, r));
    }

    void process() {
        vector<int> st;
        for (int i = 1; i <= n; i++) {
            if (st.size() && a[st.back()] + a[i] == k) {
                update(st.back(), i, 1);
                st.pop_back();
            }
            else st.push_back(i);
        }

        for (int t = 1; t <= tt; t++) {
            int l = qu[t].first, r = qu[t].second;
            if (get(l, r) == 1) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}


signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "sumk"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        int l, r; cin >> l >> r;
        qu[i] = {l, r};
    }

    // if (sub1::check()) sub1::process();
    // else if (sub2::check()) sub2::process();
    // else sub3::process();

    sub3::process();

    return 0;
}