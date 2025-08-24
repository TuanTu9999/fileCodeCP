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

string s;

void sol(){
	int l = 0, r = s.size() - 1;
	while(s[l] == '0') l++;
	while(s[r] == '0') r--;

	bool check = 0;
	int tmp, ans;
	tmp = ans = 0;
	for(int i = l; i <= r; i++){
		if(s[i] == '0') tmp++;
		else{
			ans += tmp;
			tmp = 0;
			check = 1;
		}
	}
	if(check) cout << ans;
	else cout << -1;
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	int t; cin >> t;
	while(t--){
		cin >> s;
		sol();
	}
	return 0;
}