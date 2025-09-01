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

bitset<maxn> nPrime;
vector<int> prime;
void sieve(int lim) {
	nPrime[0] = nPrime[1] = 1;
	for (int i = 2; i * i <= lim; i++) if (!nPrime[i]) {
		for (int j = i * i; j <= lim; j += i) {
			nPrime[j] = 1;
		}
	}

	for (int i = 2; i <= lim; i++) if (!nPrime[i])
		prime.emplace_back(i);
}

string bin(int mask) {
	string s = "";
	for (int i = 4; i >= 0; i--) {
		s += (char)((mask >> i & 1) + '0');
	}
	return s;
}

long long count(const vector<long long> &val, long long m) {
	int n = val.size();
	long long Ans = 0;
	for (int mask = 1; mask < (1 << n); mask++) {
		long long t = 1;
		for (int i = 0; i < n; i++) if (mask & (1 << i)) {
			t *= val[i];
		}
		if (__builtin_popcount(mask) & 1)
			Ans += m / t;
		else
			Ans -= m / t;
	}
	return m - Ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    long long n, k;
    cin >> n >> k;

    vector<long long> divi;
    long long Ans = 0;
    for (long long i = 1; i * i <= n; i++) {
    	if (n % i == 0) {
    		divi.emplace_back(i);
    		long long t = n / i;
    		if (t ^ i) {
    			divi.emplace_back(t);
    		}
    	}
    }

	sieve(sqrt(n));

	for (long long x : divi) {
		long long t = n / x;
		vector<long long> val;
		for (int pr : prime) {
			if (1ll * pr * pr > t) break;
			if (t % pr == 0) {
				val.emplace_back(pr);
				while (t % pr == 0)
					t /= pr;
			}
		}
		if (t > 1) {
			val.emplace_back(t);
		}

		Ans += count(val, k / x) * x;
	}

	cout << Ans;

    return 0;
}
