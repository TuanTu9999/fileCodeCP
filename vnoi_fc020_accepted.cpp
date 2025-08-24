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

int n, a[maxn];
llong ti, suu;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(n == 1){
		cout << a[1];
		return 0;
	}
	sort(a + 1, a + n + 1);
	int m = ceil(1.0 * n / 2);
	for(int i = m; i <= n; i++) suu += a[i];
	for(int i = m - 1; i > 0; i--) ti += a[i];
	cout << suu - ti;
	return 0;
}
