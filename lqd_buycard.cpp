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

llong p, n1, n2, t1, t2, c;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(FILENAME".INP", "r", stdin);
	//freopen(FILENAME".OUT", "w", stdout);
	int t; cin>>t;
	while(t--){
		cin>>c>>p>>n1>>n2>>t1>>t2;
		llong l = 0, r = c/p, ans = 0;
		while(l <= r){
			llong m = l + (r - l) / 2;
			if(m * p + m/n1 * t1 + m/n2 * t2 <= c){
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}