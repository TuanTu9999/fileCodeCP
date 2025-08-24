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

bool check(int k){
	int l = 0, tmp = 1;
	for(int r = 0; r < n; r++){
		if(tmp >= k) return true;
		while(a[r] < tmp && l < n){
			tmp--;
			l++;
		}
		tmp++;
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
	for(int i = 0; i < n; i++) cin >> a[i];
	int l = 1, r = n;
	while(l <= r){
		int m = l + (r - l) / 2;
		if(check(m)){
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}

	cout << ans - 1;
	return 0;
}