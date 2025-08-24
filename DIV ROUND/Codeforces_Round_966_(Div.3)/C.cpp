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

int a[maxn], n, tt, m;
string s;


bool check(string& s, int n){
	if((int)s.size() != n) return false;
	map<int, char> ic;
	map<char, int> ci;
	for(int i = 0; i < (int)s.size(); i++){
		if(ic.count(a[i]) == 0) ic[a[i]] = s[i];
		if(ci.count(s[i]) == 0) ci[s[i]] = a[i];
		if(ic[a[i]] != s[i] || ci[s[i]] != a[i]) return	false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>tt;
	while(tt--){
		cin>>n;
		for(int i = 0; i < n; i++) cin>>a[i];
		cin>>m;
		while(m--){
			cin>>s;
			if(check(s, n)) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}