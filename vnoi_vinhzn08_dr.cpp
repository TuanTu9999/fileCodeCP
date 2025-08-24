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

int n, a[maxn];
llong h, ans;

bool check(llong k){
	llong res = 0;
	for(int i = 0; i < n - 1; i++){
		res += min(k, 1LL * a[i + 1] - a[i]);
	}
	res += k;
	return (res >= h);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> h;
	for(int i = 0; i < n; i++) cin >> a[i];
	llong l = 1, r = h;
	while(l <= r){
		llong mid = l + (r - l) / 2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}