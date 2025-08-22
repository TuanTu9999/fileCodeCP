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
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, a[maxn];
bool lastVis[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "BacNam"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    	a[i] += 2;
    }

    int cnt[2];
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; i++) {
		if (!lastVis[a[i] - 2]) {
			cnt[a[i] & 1]++;
		}
		lastVis[a[i]] = 1;
	}

	cout << cnt[1] << '\n' << cnt[0];

    return 0;
}