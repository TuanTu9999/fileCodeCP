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

int n, ma = -1e9, mi = 1e9, mi1 = 1e9;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		ma = max(ma, x);
		mi = min(mi, x);
		if(mi1 > x && mi != x) mi1 = x;
	}
	cout << max(ma - mi, - mi1 - mi);
	return 0;
}