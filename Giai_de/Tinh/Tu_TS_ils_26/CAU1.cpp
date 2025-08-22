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

#define maxn ((int)(2e6) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = ((int)(1e9) + 7);
// #define ONLINE_JUDGE

int cntNumDigit(int n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "CAU1"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int sum = 0, lim = 2e6;
    vector<int> memo;
    memo.emplace_back(0);
    for (int x = 1; x <= lim; x++) {
        sum += cntNumDigit(x);
        memo.emplace_back(sum);
    }

    int n; cin >> n;
    int pos = lower_bound(all(memo), n) - memo.begin();
    if (memo[pos] != n) cout << 0;
    else cout << pos;

    return 0;
}