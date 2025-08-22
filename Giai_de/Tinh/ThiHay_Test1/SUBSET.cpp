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

int n, S;
long long pre[maxn];
map<long long, int> last;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
    	int x;
    	cin >> x;
    	pre[i] = pre[i - 1] + x;
    }

    // for (int i = 1; i <= n; i++) cout << pre[i] << ' ';
    // cout << '\n';

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = i; j <= n; j++) if (pre[j] - pre[i - 1] == S) {
	// 		cout << i << ' ' << j << '\n';
	// 	}
	// }

    last[0] = 0;
    int Ans = 1e9;
    for (int i = 1; i <= n; i++) {
    	auto it = last.find(pre[i] - S);
    	if (it != last.end()) {
    		// cout << (*it).second << ' ' << i << '\n';
    		minimize(Ans, i - (*it).second);
    	}
    	last[pre[i]] = i;
    }

    if (Ans != (int)1e9) cout << Ans;
    else cout << -1;

    return 0;
}