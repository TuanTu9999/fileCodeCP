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

const int N = 1e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 2e9;
const long long ool = 1e18;

int n, c[(int)1e6 + 3];
vector<int> a;

int main(){
	fastio;
	//fileio("inout");
	cin>>n;
	for(int i = 0, x; i < n; i++){
		cin>>x;
		if(c[x] == 0) a.pb(x);
		c[x]++;
	}
	int e = *max_element(all(a));
	for(int i = *min_element(all(a)); i <= e; i++){
		if(c[i]) cout<<i<<' '<<c[i]<<'\n';
	}
	el;
	for(int x : a) cout<<x<<' '<<c[x]<<'\n';
	cerr<<"\nRUN TIME: "; cerr<<(1.0*clock()/CLOCKS_PER_SEC)<<'\n';
	return 0;
}