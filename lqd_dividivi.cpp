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
const int MOD = 1e7 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

bool kt[maxn];
int prime[maxn], id = 0;
void sieve(int n){
	for(int i = 2; i * i <= n; i++){
		if(!kt[i]){
			for(int j = i * i; j <= n; j += i) kt[j] = 1;
		}
	}
	for(int i = 2; i <= n; i++) if(!kt[i]) prime[++id] = i;
}

llong sumDivi(int n){
	int ans = 1;
	for(int k = 1; k <= id; k++){
		int i = 1;
		llong tmp = prime[k];
		int res = 0;
		while(tmp <= n){
			res += n / tmp;
			i++;
			tmp *= prime[k];
		}
		if(res == 0) break;
		ans = (1LL * (ans % MOD) * (1LL * (1LL * (1LL * (res + 1) % MOD * (res + 2) % MOD) % MOD * 5000004) % MOD)) % MOD;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	sieve(1e6);
	while(true){
		int x; cin>>x;
		if(x == 0) return 0;
		cout<<sumDivi(x)<<'\n';
	}
	return 0;
}