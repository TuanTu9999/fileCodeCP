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

const int maxn = 1e7 + 3;
const int MOD = 1e9 + 7;
const int oo = 1e7;
const long long ool = 1e18;
#define FILENAME "maxtime"

int n, k, ans, id[2 * maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		if(id[oo + x + k]) ans = max(ans, i - id[oo + x + k]);
		if(id[oo + x - k]) ans = max(ans, i - id[oo + x - k]);
		if(id[oo + x] == 0) id[oo + x] = i;
	}
	if(ans) cout << ans;
	else cout << -1;
	return 0;
}