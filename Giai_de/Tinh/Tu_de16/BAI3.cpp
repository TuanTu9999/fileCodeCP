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

const int lim = 2010;
int tree[lim + 10];
void update(int pos, int val) {
	pos++;
	for (; pos <= lim; pos += pos & -pos) {
		tree[pos] += val;
	}
}
int get(int pos) {
	pos++;
	int res = 0;
	for (; pos; pos -= pos & -pos) {
		res += tree[pos];
	}
	return res;
}

int n, k, a[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "BAI3"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	int x; cin >> x;
    	if (x > 0) a[++a[0]] = x;
    	else update(-x, 1);
    }

    long long Ans = 0;
    for (int i = 1; i <= a[0]; i++) {
    	Ans += get(a[i]) - get(a[i] - k - 1);
    }

    cout << Ans;

    return 0;
}