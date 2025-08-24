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

int n, factor[maxn];
llong ans = 1;

int minpf[maxn];
void sieve(int n){
	for(int i = 2; i * i <= n; i++){
		if(minpf[i] == 0){
			for(int j = i * i; j <= n; j += i){
				if(minpf[j] == 0) minpf[j] = i;
			}
		}
	}
}

void facDivi(int a){
	while(a > 1){
		int t = minpf[a], cnt = 0;
		if(t == 0) t = a;
		while(a % t == 0){
			cnt++;
			a /= t;
		}
		factor[t] += cnt;
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
	sieve(1e6);
	cin >> n;
	for(int i = 2; i <= n; i++) facDivi(i);
	for(int i = 2; i <= (int)1e6; i++){
		if(factor[i]){
			if(factor[i] & 1) factor[i]--;
			ans = (1LL * ans % MOD * binPow(i, factor[i])) % MOD;
		}
	}
	cout << ans;
	return 0;
}