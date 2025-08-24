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

int n, k, ma;
llong sum;

void sol(){
	cin >> n >> k;
	ma = sum = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		ma = max(ma, x);
		sum += x;
	}
	if(sum % k == 0 && 1LL * k * ma <= sum) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	int t; cin >> t;
	while(t--) sol();
	return 0;
}