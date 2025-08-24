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

const int maxn = 5e3 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;

//link: https://oj.vnoi.info/problem/vnoicup24_r2_a

int t, n;
llong x;

void sol(){
	cin>>n>>x;
	vector<llong> a(n);
	int ans = 0;
	for(llong& in : a) cin>>in;
	for(int i = 1; i <= n; i++){
		int id = -1;
		for(int j = a.size() - 1; j >= 0; j--){
			if(x * i >= a[j]){
				id = j;
				break;
			}
		}
		if(id == -1) break;
		a.erase(a.begin() + id);
		ans++;
	}
	cout<<ans<<'\n';
}

int main(){
	fastio;
	//fileio("inout");
	cin>>t;
	while(t--) sol();
	cerr<<"\nRUN TIME: "; cerr<<(1.0*clock()/CLOCKS_PER_SEC)<<'\n';
	return 0;
}