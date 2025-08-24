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

int tt, a, b, n;

void sol(int& a, int& b, int& n){
	llong l = 1, r = 1LL * n * max(a, b), lcm = a * b / __gcd(a, b);
	while(l <= r){
		llong mid = l + (r - l) / 2;
		if(mid/a + mid/b - mid/lcm < n) l = mid + 1;
		else r = mid - 1;
	}
	cout<<l<<'\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>tt;
	while(tt--){
		cin>>a>>b>>n;
		sol(a, b, n);
	}
	return 0;
}