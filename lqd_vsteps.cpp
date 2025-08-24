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
const int MOD = 14062008;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

// f[i] : số cách đi từ bậc thang thứ 1 -> i.
// d : lưu các vị trí mà tại vị trí đó bậc thang hư.
int n, k, f[maxn], d[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> k;
	for(int i = 0; i < k; i++) cin >> d[i];
	// trường hợp cơ sở f[1] = 1.
	f[1] = 1;
	for(int i = 2; i <= n; i++){
		if(binary_search(d, d + k, i)) f[i] = 0;
		else{
			f[i] = f[i - 1] + f[i - 2];
			f[i] %= MOD;
		}
	}
	cout << f[n];
	return 0;
}