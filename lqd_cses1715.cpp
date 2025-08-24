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
int c[260], ans = 1;

int binPow(llong a, int b){
	llong res = 1;
	while(b){
		if(b & 1) (res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

int giaithua(int a){
	int res = 1;
	for(int i = 2; i <= a; i++) res = (1LL * res * i) % MOD; 
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>s;
	for(int i = 2; i <= (int)s.size(); i++) ans = (1LL * ans * i) % MOD;
	for(char x : s) c[(int)x]++;

	for(int i = (int)'a'; i <= (int)'z'; i++){
		if(c[i]) ans = (1LL * ans * binPow(giaithua(c[i]), MOD - 2)) % MOD;
	}
	cout<<ans;
	return 0;
}