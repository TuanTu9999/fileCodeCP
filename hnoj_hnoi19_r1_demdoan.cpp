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
#define FILENAME "BAI1"

llong n, ans;

bool check(llong x){
	llong a, b;
	llong y = 2LL * n / x;
	a = x - y + 1;
	b = x + y - 1;
	return (a % 2 == 0 && b % 2 == 0);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(llong i = 1; i * i <= n; i++){
		if(n % i == 0){
			ans += check(i);
			if(i * i != n) ans += check(n / i);
		}
	}
	cout << ans;
	return 0;
}