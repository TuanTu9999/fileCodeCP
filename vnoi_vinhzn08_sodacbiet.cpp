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

const int N = 1e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 2e9;
const long long ool = 1e18;

int l, r, ans;

void sieve(int n, vector<int>& c){
	for(int i = 2; 1LL * i * i <= n; i++){
		for(int j = i * i; j <= n; j += i){
			c[j] += i;
			if(i * i != j) c[j] += j/i;
		}
	}
}

int main(){
	fastio;
	//fileio("inout");
	cin>>l>>r;
	vector<int> c(r + 1, 1);
	sieve(r, c);
	c[0] = c[1] = 0;
	for(int i = l; i <= r; i++){
		if(c[i] > i) ans++;
	}
	cout<<ans;
	cerr<<"\nRUN TIME: "; cerr<<(1.0*clock()/CLOCKS_PER_SEC)<<'\n';
	return 0;
}