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

const int maxn = 5e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME "TROCHOI"

int n, mi = 1e9;
pii a[maxn];

//pre: prefix_sum
//f[i]: gia tri can thiet de an cac con ca tu i -> n

llong pre[maxn], f[maxn];
bool ans[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
        mi = min(mi, x);
		a[i] = pii(x, i);
	}

	if(n == 1) return cout << 1, 0;

	//init
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].first;
    
    f[n + 1] = 0;
	for(int i = n; i > 0; i--){
		f[i] = max(f[i + 1] - a[i].first, 1LL * a[i].first + 1LL);
	}

	//sol
	for(int i = 1; i <= n; i++){
        if(a[i].first == mi) ans[a[i].second] = 0;
		else if(pre[i] >= f[i + 1]) ans[a[i].second] = 1;
		else ans[a[i].second] = 0;
	}

	for(int i = 1; i <= n; i++) cout << ans[i];
	return 0;
}
