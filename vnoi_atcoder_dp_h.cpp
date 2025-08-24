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

const int maxn = 1e3 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int h, w, f[maxn][maxn];
char a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> h >> w;
	for(int i = 1; i <= h; i++)
		for(int j = 1; j <= w; j++)
			cin >> a[i][j];

	if(a[1][1] == '#') return cout << 0, 0;
	f[1][1] = 1;

	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(a[i][j] == '.'){
				f[i][j] += f[i - 1][j] + f[i][j - 1];
				f[i][j] %= MOD;
			}
			else f[i][j] = 0;
		}
	}

	cout << f[h][w];
	return 0;
}