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

bool check(int d) {
	int curD = d;
	while (d) {
		int digit = d % 10;
		d /= 10;

		if (digit == 0 || curD % digit != 0) return 0;
	}
	return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int l, r;
    cin >> l >> r;

    vector<int> Ans;
    for (int i = l; i <= r; i++) if (check(i)) {
    	Ans.emplace_back(i);
    }

    cout << Ans.size() << '\n';
    for (int x : Ans) cout << x << ' ';

    return 0;
}