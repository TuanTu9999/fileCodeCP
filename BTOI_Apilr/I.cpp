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

const int maxn = 1003;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME "maxsquare"

int n, ans = 1e6, pre[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x; cin >> x;
			pre[i][j] = pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1] + x;
		}
	}
	for(int i = 3; i <= n; i++)
		for(int j = 3; j <= n; j++)
			ans = min(ans, pre[i][j] - pre[i][j - 3] - pre[i - 3][j] + pre[i - 3][j - 3]);

	cout << ans;
	return 0;
}