#include <bits/stdc++.h>
#define llong            unsigned long long
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

llong n;
vector<llong> a;

void init(){
	llong val = 1;
	for(int i = 1; i <= 62; i++){
		val *= 2LL;
		a.push_back(val);
		a.push_back(3LL * val);
	}
	a.push_back(3LL * val);
	sort(a.begin(), a.end());
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	init();
	cin >> n;
	int id = upper_bound(a.begin(), a.end(), n) - a.begin() - 1;
	if(n - a[id] == 18446744073709550576) cout << 0; 
	else cout << n - a[id];
	return 0;
}