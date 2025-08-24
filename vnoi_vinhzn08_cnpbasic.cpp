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

int n, q, a[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	while(q--){
		int type, x; cin >> type >> x;
		if(type == 1){
			if(binary_search(a, a + n, x)) cout << "YES";
			else cout << -1;
		}
		else if(type == 2){
			int id = lower_bound(a, a + n, x) - a;
			if(a[id] == x) cout << id + 1;
			else cout << -1;
		}
		else{
			int id = upper_bound(a, a + n, x) - a;
			if(a[id - 1] == x) cout << id;
			else cout << -1;
		}
		cout << '\n';
	}
	return 0;
}