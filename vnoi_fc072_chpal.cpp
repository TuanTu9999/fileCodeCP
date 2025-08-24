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

int n, q;
string s;

bool dx(int l, int r){
	while(l < r){
		if(s[l] != s[r]) return false;
		l++;
		r--;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> q >> s;
	s = ' ' + s;
	while(q--){
		int l, r; cin >> l >> r;
		if(dx(l, r)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}