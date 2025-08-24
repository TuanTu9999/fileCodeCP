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
const int MOD = 1234567891;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, f[maxn], minpf[maxn], ma, ans = 1;

void sieve(int n){
	for(int i = 2; i * i <= n; i++){
		if(!minpf[i]){
			for(int j = i * i; j <= n; j += i){
				if(!minpf[j]) minpf[j] = i;
			}
		}
	}
}

void factorDiv(int a){
	while(a > 1){
		int t = minpf[a];
		if(t == 0) t = a;
		while(a % t == 0){
			a /= t;
			f[t]++;
		}
		ma = max(ma, t);
	}
}

int binPow(llong a, int b){
	llong res = 1;
	a %= MOD;
	while(b){
		if(b & 1) (res *= a) %= MOD;
		(a *= a) %= MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	sieve(1e5);
	cin >> n;
	for(int i = 1; i <= n; i++) factorDiv(i);
	for(int i = 2; i <= ma; i++){
		ans = (1LL * ans % MOD * binPow(i, f[i] / 2 * 2)) % MOD;
	}
	cout << ans;
	return 0;
}