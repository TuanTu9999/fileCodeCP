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
const int MOD = 998244353;
// #define ONLINE_JUDGE

long long fact[maxn], ifact[maxn];

long long binPow(long long a, int b) {
	if (b < 0) return 0;
	long long res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

long long C(int n, int k) {
	if (n < k) return 0;
	return ((fact[n] * ifact[k]) % MOD * ifact[n - k]) % MOD;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "WORDS"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    int lim = max(n, m);
    fact[1] = 1;
    for (int i = 2; i <= lim; i++) 
    	fact[i] = fact[i - 1] * i % MOD;
    ifact[lim] = binPow(fact[lim], MOD - 2);
    for (int i = lim - 1; i > 0; i--)
    	ifact[i] = ifact[i + 1] * (i + 1) % MOD;

    cout << ((C(m, n - 1) * (n - 2)) % MOD * binPow(2ll, n - 3) % MOD) % MOD;

    return 0;
}
