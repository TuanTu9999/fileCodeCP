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

int n, a[maxn];
llong target, ans;

llong sol(int id, llong sum){
	if(id == 0){
		return abs((target - sum) - sum);
	}
	else{
		return min(sol(id - 1, sum + a[id]), sol(id - 1, sum));
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		target += a[i];
	}
	cout << sol(n, 0);
	return 0;
}