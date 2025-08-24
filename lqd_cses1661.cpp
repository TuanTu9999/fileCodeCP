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

const int maxn = 2e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, x;
llong ans, sum;
map<llong, int> c;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	c[0] = 1;
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		int val; cin >> val;
		sum += val;
		auto it = c.find(sum - x);
		if(it != c.end()) ans += (*it).second;
		c[sum]++;
	}
	cout << ans;
	return 0;
}