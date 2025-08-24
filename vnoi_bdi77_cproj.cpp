#include <bits/stdc++.h>
#define llong            long long
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back

using namespace std;

const int maxn = 1e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME "CPROJ"

int n, b[maxn], ans;
llong f[maxn], a[maxn];
llong lcm;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	//init
	lcm = 1LL * b[0] * b[1] / __gcd(b[0], b[1]);
	for(int i = 2; i < n; i++) lcm = lcm / __gcd(lcm, (llong)b[i]) * b[i];
	for(int i = 0; i < n; i++) a[i] *= (lcm / b[i]);

	//sol
	for(int i = 0; i < n; i++){
		int j = lower_bound(f + 1, f + ans + 1, a[i]) - f;
		ans = max(ans, j);
		f[j] = a[i];
	}
	cout << ans;
	return 0;
}