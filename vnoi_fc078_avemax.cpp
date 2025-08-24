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

int n, a[maxn], ans;
llong pre[maxn];

bool check(int avg){
	memset(pre, 0, sizeof pre);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i] - avg;

	llong mi = 0;
	for(int i = 1; i <= n; i++){
		if(pre[i] - mi >= 0) return true;
		mi = min(mi, pre[i]);
	}

	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int l = *min_element(a + 1, a + n + 1), r = *max_element(a + 1, a + n + 1);
	while(l <= r){
		int m = l + (r - l) / 2;
		if(check(m)){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}

	cout << ans;
	return 0;
}