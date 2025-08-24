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

int n, k;
vector<int> f, unf;
llong ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		int h; cin >> h;
		if(h > 0) f.push_back(h);
		else unf.push_back(-h);
	}

	sort(unf.begin(), unf.end());

	for(int x : f){
		int id1 = lower_bound(unf.begin(), unf.end(), x - k) - unf.begin();
		int id2 = upper_bound(unf.begin(), unf.end(), x) - unf.begin();
		ans += id2 - id1;
	}
	
	cout << ans;
	return 0;
}