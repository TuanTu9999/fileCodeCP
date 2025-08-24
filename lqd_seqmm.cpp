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

int n, ans = 1e6, a[maxn];
vector<pii> b;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int mi = *min_element(a, a + n), ma = *max_element(a, a + n);
	for(int i = 0; i < n; i++){
		if(a[i] == mi || a[i] == ma) b.push_back({a[i], i});
	}
	for(int i = 1; i < (int)b.size(); i++){
		if(b[i].first != b[i - 1].first){
			ans = min(ans, b[i].second - b[i - 1].second + 1);
		}
	}
	cout << ans;
	return 0;
}