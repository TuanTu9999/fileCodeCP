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

const int maxn = 501;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;

int f[maxn][maxn], a, b;

int cat(int a, int b){
	if(a == b) return 0;
	if(f[a][b] != -1) return f[a][b];
	int &ans = f[a][b];
	ans = ooi;
	for(int i = 1; i < b; i++)
		ans = min(ans, cat(a, i) + cat(a, b - i) + 1);
	for(int i = 1; i < a; i++)
		ans = min(ans, cat(i, b) + cat(a - i, b) + 1);
	return ans;
}

int main(){
	fastio;
	//fileio("inout");
	memset(f, -1, sizeof f);
	cin>>a>>b;
	cout<<cat(a, b);
	cerr<<"\nRUN TIME: "; cerr<<(1.0*clock()/CLOCKS_PER_SEC)<<'\n';
	return 0;
}