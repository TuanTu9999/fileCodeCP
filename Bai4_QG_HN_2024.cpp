#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;

long long MUL(long long x, long long y) {
	x %= MOD;
	y %= MOD;
	return ((x * y) % MOD + MOD) % MOD;
}
long long ADD(long long x, long long y) {
	return ((x + y) % MOD + MOD) % MOD;
}

int n;
int a[maxn], b[maxn];
vector<int> adj[maxn];
long long dp[maxn], Ans;

void dfs(int u, int p) {
	long long sum = 0;
	long long mul = 1;
	for (int v : adj[u]) if (v != p) {
		dfs(v, u);
		mul = MUL(mul, dp[v] + 1);
		sum = ADD(sum, dp[v]);
	}
	dp[u] = ADD(MUL(a[u] + 1, mul), -1);

	Ans = ADD(Ans, MUL(dp[u] - sum, b[u]));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	freopen("TSTD.INP", "r", stdin);
	freopen("TSTD.OUT", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	dfs(1, 0);

	cout << Ans;

	return 0;
}
