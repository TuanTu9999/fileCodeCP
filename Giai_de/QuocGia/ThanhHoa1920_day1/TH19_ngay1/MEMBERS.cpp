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
const int MOD = ((int)(1e9) + 7);

int n, a[maxn];
long long k;
int cost[maxn];

namespace sub1 {
    bool checkSub() {
        return n <= 2000;
    }

    void process() {
        vector<int> Ans;
        for (int i = 0; i < n; i++) {
            int maxVal = -1, pos = -1, cnt = 0;
            for (int j = 1; j <= n; j++) if (a[j] != (int)(-1e9)) {
                cnt++;
                if (maxVal < a[j]) {
                    maxVal = a[j];
                    pos = j;
                }

                if (cnt > k) break;
            }

            a[pos] = -1e9;
            Ans.push_back(maxVal);

            int cost = 0;
            for (int j = pos - 1; j >= 1; j--) if (a[j] != (int)(-1e9)) {
                cost++;
            }
            k -= cost;
        }

        for (int x : Ans) cout << x << ' ';
    }
}

namespace sub2 {
    int comp[maxn];

    int bit[maxn], lim = 2e5 + 1;
    void updateBIT(int pos, int val) {
        for (; pos <= lim; pos += pos & -pos) {
            bit[pos] += val;
        }
    }
    int getBIT(int pos) {
        int res = 0;
        for (; pos > 0; pos -= pos & -pos) {
            res += bit[pos];
        }
        return res;
    }

    pii tree[maxn << 2];
    void updateSeg(int pos, pii val, int id = 1, int l = 1, int r = n) {
        if (pos < l || r < pos) return;
        if (l == r) {
            tree[id] = val;
            return;
        }
        int mid = l + r >> 1;
        updateSeg(pos, val, id << 1, l, mid);
        updateSeg(pos, val, id << 1 | 1, mid + 1, r);
        tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
    }
    pii getSeg(int st, int en, int id = 1, int l = 1, int r = n) {
        if (en < l || r < st) return {-1e9, -1e9};
        if (st <= l && r <= en) return tree[id];

        int mid = l + r >> 1;
        return max(getSeg(st, en, id << 1, l, mid),
                   getSeg(st, en, id << 1 | 1, mid + 1, r));
    }

    void process() {
        for (int i = 1; i <= n; i++) {
            updateBIT(i, 1);
            updateSeg(i, {a[i], -i});
        }

        vector<int> Ans;
        for (int rep = 0; rep < n; rep++) {
            int l = 1, r = n, maxPos = 1;
            while (l <= r) {
                int mid = l + r >> 1;
                if (getBIT(mid) >= min(k + 1, 1ll * n - rep)) {
                    maxPos = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            pii res = getSeg(1, maxPos);
            int val = res.first;
            int idx = -res.second;

            Ans.push_back(val);

            k -= getBIT(idx) - 1;
            updateBIT(idx, -1);
            updateSeg(idx, {-1e9, -1e9});
        }

        for (int x : Ans) cout << x << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("MEMBERS.INP", "r", stdin);
    freopen("MEMBERS.OUT", "w", stdout);


    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (sub1::checkSub()) sub1::process();
    else sub2::process();

    return 0;
}