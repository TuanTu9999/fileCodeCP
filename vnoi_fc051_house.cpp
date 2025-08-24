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
#define FILENAME ""

int n, a[maxn], pre[maxn], suf[maxn], ans = -ooi;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	pre[0] = -ooi;
	for(int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], a[i]);
	suf[n + 1] = ooi;
	for(int i = n; i > 0; i--) suf[i] = min(suf[i + 1], a[i]);

	for(int i = 1; i <= n; i++){
		//if(pre[i] == suf[i]) ans = max({ans, pre[i] - suf[i - 1], pre[i - 1] - suf[i]});
		ans = max(ans, pre[i] - suf[i]);
	}
	cout << ans;
	return 0;
}