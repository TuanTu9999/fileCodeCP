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

#define maxn ((int)(3e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, a[maxn];
long long Ans[maxn];

namespace sub1 {
	inline bool checkSub() {
		return n <= 16;
	}

	void process() {
		vector<vector<int>> db(n + 1, vector<int>());

		for (int mask = 1; mask < (1 << n); mask++) {
			vector<int> se;
			for (int i = 0; i < n; i++) if (mask & (1 << i)) {
				se.emplace_back(a[i + 1]);
			}
			long long sum = 0;
			for (int i = 0; i < se.size(); i++) {
				for (int j = i + 1; j < se.size(); j++) {
					sum += abs(se[i] - se[j]);
				}
			}
			if (maximize(Ans[__builtin_popcount(mask)], sum)) {
				// db[__builtin_popcount(mask)] = se;
			}
		}

		// for (int k = 2; k <= n; k++) {
		// 	for (int x : db[k]) cout << x << ' ';
		// 	cout << '\n';
		// }
	}
}

namespace sub2 {
	long long pre[maxn];

	void calc0() {
		long long res = 0;
		int en = n - (n % 2 == 1);

		vector<long long> sum(n + 1, 0);
		for (int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] + a[i];

		for (int k = 2; k <= en; k += 2) {
			int len = k >> 1;
			res -= pre[len];
			res += pre[n] - pre[n - len];

			Ans[k] = res + sum[len] - (sum[n] - sum[n - len]);
		}
	}

	void calc1() {
		long long res = 0;
		int en = n - (n % 2 == 0);

		for (int k = 3; k <= en; k += 2) {
			int len = k - 1 >> 1;
			res -= pre[len];
			res += pre[n] - pre[n - len];

			Ans[k] = res;
		}
	}

	long long pre1[maxn], pre2[maxn];
	void process() {
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] + 2 * a[i];

		calc0();
		calc1();
	}
}

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

    sub2::process();

	for (int k = 2; k <= n; k++) {
		cout << Ans[k] << ' ';
	}

    return 0;
}
