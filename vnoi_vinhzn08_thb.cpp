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

int n, k, p[40];
llong ans[40];
map<int, int> c;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>n>>k;
	int tmp = k;
	p[0] = 1;
	k = min(30, k);
	for(int i = 1; i <= k; i++) p[i] = p[i - 1] * 2;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		for(int j = 1; j <= k; j++){
			auto it = c.find(p[j] - x);
			if(it != c.end()) ans[j] += (*it).second;
		}
		c[x]++;
	}
	for(int i = 1; i <= tmp; i++){
		if(i <= k) cout<<ans[i]<<'\n';
		else cout<<"0\n";
	}
	return 0;
}