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

int a, b, m, A[maxn], B[maxn], ans = 1e9;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> a >> b >> m;
	for(int i = 1; i <= a; i++) cin >> A[i];
	for(int i = 1; i <= b; i++) cin >> B[i];
	while(m--){
		int x, y, c; cin >> x >> y >> c;
		ans = min(ans, A[x] + B[y] - c);
	}
	cout << min(ans, *min_element(A + 1, A + a + 1) + *min_element(B + 1, B + b + 1));
	return 0;
}