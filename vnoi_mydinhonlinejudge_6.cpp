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

int n, a[(int)1e6 + 3];

void kadane(){
	llong ans, s;
	ans = -ool;
	s = 0;
	int l = 0, r = 0, tmpl = 0;
	for(int i = 0; i < n; i++){
		s += a[i];
		if(s < 0){
			tmpl = i + 1;
			s = 0;
		}
		else if(ans < s){
			l = tmpl;
			r = i;
			ans = s;
		}
	}
	cout<<ans<<'\n';
	for(int i = l; i <= r; i++) cout<<a[i]<<' ';
}

int main(){
	fastio;
	fileio("DOANCON");
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	kadane();
	return 0;
}