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

long long dp[1 << 18 | 1][100];
string n;
int m;

string bin(int mask) {
	string s = "";
	for (int i = 3; i >= 0; i--) {
		s += (char)((mask >> i & 1) + '0');
	}
	return s;
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

    int len = n.size();

    dp[0][0] = 1;
    for (int mask = 0; mask < (1 << len); mask++) {
    	for (int rem = 0; rem < m; rem++) {
    		for (int i = 0; i < len; i++) if (!(mask & (1 << i))) {
    			if (mask == 0 && n[i] == '0') continue; 
	    		int nex_mask = mask ^ (1 << i);
	    		int nex_rem = (10ll * rem + (n[i] - '0')) % m;
	    		dp[nex_mask][nex_rem] += dp[mask][rem];
	    	}
    	}
    }

    long long Ans = dp[(1 << len) - 1][0];

    int cnt[10];
    long long fact[19];
    fact[1] = 1;
    for (int i = 2; i <= 18; i++)
    	fact[i] = fact[i - 1] * i;
    memset(cnt, 0, sizeof cnt);
    for (char x : n) cnt[x - '0']++;

    for (int i = 0; i < 10; i++) if (cnt[i] > 1)
    	Ans /= fact[cnt[i]];

    cout << Ans;

    return 0;
}
