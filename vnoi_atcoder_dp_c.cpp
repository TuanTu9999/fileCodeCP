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

int n, a, b, c;
llong f[maxn][3];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a >> b >> c;
		f[i][0] = max(f[i - 1][1], f[i - 1][2]) + a;
		f[i][1] = max(f[i - 1][0], f[i - 1][2]) + b;
		f[i][2] = max(f[i - 1][0], f[i - 1][1]) + c;
	}

	cout << max({f[n][0], f[n][1], f[n][2]});
	return 0;
}