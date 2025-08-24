#include <bits/stdc++.h>
#define llong            long long
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define fastio           ios_base::sync_with_stdio(0); cin.tie(0);
#define fin(NAME)        freopen(NAME".INP", "r", stdin)
#define fou(NAME)        freopen(NAME".OUT", "w", stdout)
#define ld               long double
#define sz(a)            sizeof a
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back
#define mp               make_pair
#define BIT(n)           (1 << n)
#define bit(mask, i)     ((mask >> i) & 1)
#define set_on(mask, i)  (mask | BIT(i))
#define set_off(mask, i) (mask & ~BIT(i))
#define all(v)           v.begin(), v.end()
#define reset(a)         memset(a, 0, sizeof a)
#define fileio(f)        fin(f); fou(f);

using namespace std;

const int maxn = 101;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;

int a[maxn][maxn], n, m, x, y;
llong s;

int main(){
	fastio;
	//fileio("inout");
	cin>>n>>m>>x>>y;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin>>a[i][j];
	}
	int x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = x2 = x3 = x4 = x;
	y1 = y2 = y3 = y4 = y;
	while(x1 > 0 && y1 > 0){
		x1--;
		y1--;
		s += a[x1][y1];
	}
	while(x2 > 0 && y2 <= m){
		x2--;
		y2++;
		s += a[x2][y2];
	}
	while(x3 <= n && y3 > 0){
		x3++;
		y3--;
		s += a[x3][y3];
	}
	while(x4 <= n && y4 <= m){
		x4++;
		y4++;
		s += a[x4][y4];
	}
	cout<<s + a[x][y];
	cerr<<"\nRUN TIME: "; cerr<<(1.0*clock()/CLOCKS_PER_SEC)<<'\n';
	return 0;
}