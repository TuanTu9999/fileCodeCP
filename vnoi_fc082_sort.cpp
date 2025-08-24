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

int n, a[maxn], len, cnt;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		a[x] = i;
	}
	cnt = 1;
	a[0] = n + 10;
	for(int i = 1; i <= n; i++){
		if(a[i] > a[i - 1]) cnt++;
		else{
			len = max(len, cnt);
			cnt = 1;
		}
	}
	cout << n - max(len, cnt);
	return 0;
}