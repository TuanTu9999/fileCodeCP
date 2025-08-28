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

#define maxn ((int)(1e3) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, m, pre[maxn][maxn], dp[maxn][maxn];
bool a[maxn][maxn];

struct RMQ {
	int rmq[LOG + 1][maxn];

	void init(int pre[]) {
		for (int j = 1; j <= m; j++)
			rmq[0][j] = pre[j];
		for (int k = 1; k <= LOG; k++) 
			for (int j = 1; j + (1 << k) - 1 <= m; j++)
				rmq[k][j] = min(rmq[k - 1][j], rmq[k - 1][j + (1 << (k - 1))]);
	}

	int get(int l, int r) {
		int k = 31 - __builtin_clz(r - l + 1);
		return min(rmq[k][l], rmq[k][r - (1 << k) + 1]);
	}
} st[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		char x; cin >> x;
	    	if (x == '1') a[i][j] = 1;
	    	else a[i][j] = 0;

	    	if (a[i - 1][j] == 0)
	    		pre[i][j] = a[i][j];
	    	else if (a[i][j] == 1)
	    		pre[i][j] = pre[i - 1][j] + 1;
    	}
    }

    for (int i = 1; i <= n; i++) {
    	st[i].init(pre[i]);
    }

    int Ans = 0;
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		int h = pre[i][j];
    		if (h == 0) continue;

    		int l = 1, r = j, L = j;
    		while (l <= r) {
    			int mid = l + r >> 1;
    			if (st[i].get(mid, j) >= h) {
    				L = mid;
    				r = mid - 1;
    			} else {
    				l = mid + 1;
    			}
    		}

    		int R = j;
    		l = j, r = m;
    		while (l <= r) {
    			int mid = l + r >> 1;
    			if (st[i].get(j, mid) >= h) {
    				R = mid;
    				l = mid + 1;
    				
    			} else {
    				r = mid - 1;
    			}
    		}

    		maximize(Ans, h * (R - L + 1));
    	}
    }

    cout << Ans;

    return 0;
}
