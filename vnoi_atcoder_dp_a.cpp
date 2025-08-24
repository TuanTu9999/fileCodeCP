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

int n, h[maxn];
llong f[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> h[i];
	f[2] = abs(h[1] - h[2]);
	for(int i = 3; i <= n; i++) 
		f[i] = min(f[i - 2] + abs(h[i] - h[i - 2]), f[i - 1] + abs(h[i] - h[i - 1]));
	cout << f[n];
	return 0;
}