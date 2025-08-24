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

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, k, c[110], ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		c[x % k]++;
	}

	ans += min(1, c[0]);
	for(int i = 1; i <= k / 2; i++){
		if(i != k - i) ans += max(c[i], c[k - i]);
		else ans++;
	}

	cout << ans;
	return 0;
}