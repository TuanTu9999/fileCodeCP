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

template<typename T>
inline void add(T &cur, const T &x) {
	cur += x;
	if (cur >= MOD) cur -= MOD;
}

int A, B, C;

namespace sub1 {
	void process() {
		int Ans = 0;

		for (int a = 2; a <= A; a++) {
			for (int b = 1; b <= B; b++) {
				for (int c = 1; c <= C; c++) {
					if (1ll * b * b - 1ll * (a - 1) * (c - 1) < 0) {
						Ans++;
						// cout << a << ' ' << b << ' ' << c << '\n';
					}
				}
			}
		}

		cout << Ans;
	}
}

namespace sub2 {
	void process() {
		int Ans = 0;
		for (int a = 2; a <= A; a++) {
			for (int c = 2; c <= C; c++) {
				int R = min((int)sqrt((a - 1) * (c - 1) - 1), B);
				add(Ans, R);
			}
		}

		cout << Ans;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> A >> B >> C;
    sub2::process();

    return 0;
}