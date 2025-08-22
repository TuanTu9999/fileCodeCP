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
const int MOD = ((int)(1e9) + 7);
// #define ONLINE_JUDGE

int n, a[maxn], diff[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "BAI1"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) diff[i] = a[i + 1] - a[i];
    diff[n] = a[1] - a[n];
    for (int i = 1; i <= n; i++) {
        if (diff[i] < 0) diff[i] = 0;
        else if (diff[i] == 0) diff[i] = 1;
        else diff[i] = 2;
    }

    int cnt[3];
    memset(cnt, 0, sizeof cnt);
    cnt[diff[1]]++;
    for (int i = 2; i <= n; i++) if (diff[i] != diff[i - 1]) {
        cnt[diff[i]]++;
    }

    cout << cnt[1] << ' ' << cnt[2] << ' ' << cnt[0];

    return 0;
}