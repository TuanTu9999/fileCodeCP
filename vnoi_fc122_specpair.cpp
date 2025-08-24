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

const int maxn = 1e7 + 3;
const int MOD = 1e9 + 7;
const int oo = 1e7;
const long long ool = 1e18;
#define FILENAME ""

int n, c[2 * maxn];
llong ans;
vector<int> f;

void init(){
	int val = 0;
	for(int i = 1; i <= 6; i++){
		val = val * 10 + 1;
		f.push_back(val);
		for(int j = 2; j <= 9; j++) f.push_back(val * j);
	}
	f.push_back(1111111);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	init();
	cin >> n;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		for(int tar : f) ans += c[oo + tar - x];
		c[oo + x]++;
	}
	cout << ans;
	return 0;
}