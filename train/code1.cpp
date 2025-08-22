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

#define maxn ((int)(1e6) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE



signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    set<int> qu;
    int Ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = qu.find(a[i]);
        if (it == qu.end()) {
            qu.insert(a[i]);
        } else {
            qu.erase(it);
        }
        maximize(Ans, (int)qu.size());
    }

    cout << Ans;

    return 0;
}