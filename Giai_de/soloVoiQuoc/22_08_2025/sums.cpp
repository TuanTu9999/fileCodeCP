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

#define maxn ((int)80)
#define ONLINE_JUDGE

int n, a[maxn];
long long dpWay[70010];
char dp[maxn][70010];
int trace[maxn][70010];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1, greater<int>());

    dpWay[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int s = 70000; s >= a[i]; s--) {
			dpWay[s] += dpWay[s - a[i]];
		}
	}

	int cnt = 0;
	for (int s = 70000; s > 0; s--) {
		if (dpWay[s]) {
			cnt++;
		}
	}

	cout << cnt << '\n';

	long long Max = *max_element(dpWay, dpWay + 70001), Ans;
	for (int s = 70000; s > 0; s--) {
		if (dpWay[s] == Max) {
			Ans = s;
			break;
		}
	}

	cout << Ans << ' ' << Max << '\n';

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int s = 70000; s >= a[i]; s--) {
			for (int j = i - 1; j >= 0; j--) {
				if (dp[j][s - a[i]]) {
					dp[i][s] = 1;
					trace[i][s - a[i]] = j;
					break;
				}
			}
		}
	}

	vector<int> Path;
	for (int i = n; i > 0; i--) {
		if (dp[i][Ans] == 0) continue;
		int idx = i, sum = Ans;

		while (idx) {
			Path.emplace_back(a[idx]);
			sum -= a[idx];
			idx = trace[idx][sum];
		}

		break;
	}

	for (int x : Path) cout << x << ' ';

    return 0;
}