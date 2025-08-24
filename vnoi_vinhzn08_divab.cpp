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

int t;
llong n, a, b;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> t;
	while(t--){
		cin >> a >> b >> n;
		llong l = 1, r = 1e18, lcm = a / __gcd(a, b) * b, ans;
		while(l <= r){
			llong mid = (l + r) / 2;
			llong cnt = mid/a + mid/b - mid/lcm;
			if(cnt >= n){
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;	
		}
		cout << ans << '\n';
	}
	return 0;
}