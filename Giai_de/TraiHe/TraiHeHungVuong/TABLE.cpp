#include <bits/stdc++.h>

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

#define maxn 401
#define ONLINE_JUDGE

int n, m, a[maxn][maxn];
int comp[maxn * maxn];
int last[maxn * maxn][maxn], dp[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
    		comp[++comp[0]] = a[i][j];
    	}
    }

    sort(comp + 1, comp + comp[0] + 1);
    comp[0] = unique(comp + 1, comp + comp[0] + 1) - comp - 1;

    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= n; j++) {
    		a[i][j] = lower_bound(comp + 1, comp + comp[0] + 1, a[i][j]) - comp - 1;
    	}
    }

    int Ans = 0;
    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= n; j++) {
			maximize(dp[j][j], last[a[i][j]][j]);
    		last[a[i][j]][j] = i;
    		maximize(Ans, i - dp[j][j]);
    	}
    	for (int l = n - 1; l > 0; l--) {
    		for (int r = l + 1; r <= n; r++) {
    			maximize(dp[l][r], max(dp[l + 1][r], dp[l][r - 1]));
    			maximize(dp[l][r], max(last[a[i][l]][r], last[a[i][r]][l]));

    			maximize(Ans, (r - l + 1) * (i - dp[l][r]));
    		}
    	}
    }

    cout << Ans;

    return 0;
}