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

int n, ans, mi;
pii a[maxn];

bool cmp(pii a, pii b){
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, l; cin >> x >> l;
		a[i] = pii(x - l, x + l);
	}
	sort(a, a + n, cmp);
	ans = 1;
	mi = a[0].second;
	for(int i = 1; i < n; i++){
		if(mi <= a[i].first){
			ans++;
			mi = a[i].second;
		}
	}
	cout << ans;
	return 0;
}