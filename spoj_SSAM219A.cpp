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

int n, k, f[maxn];

void sol(){
	memset(f, 0, sizeof f);
	f[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int step = 1; step <= min(i, k); step++){
			f[i] += f[i - step];
			f[i] %= MOD;
		}
	}
	cout << f[n] << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		sol();
	}
	return 0;
}