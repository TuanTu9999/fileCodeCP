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

int n, ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}

	cin >> n;
	vector<int> b(n);
	for(int& x : b) cin >> x;
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());

	for(int i = 0; i < (int)b.size(); i++){
		int it = upper_bound(b.begin(), b.end(), b[i] + n - 1) - b.begin() - 1;
		ans = max(ans, it - i + 1);
	}
	
	cout << n - ans;
	return 0;
}