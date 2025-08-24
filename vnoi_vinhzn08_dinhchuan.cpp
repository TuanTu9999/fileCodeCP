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
#define FILENAME "TUDEPZAI"

int n, a[maxn];
llong ans1, ans2;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	sort(a, a + n);
	int m1 = a[n / 2 - 1], m2 = a[n / 2];
	for(int i = 0; i < n; i++){
		ans1 += abs(m1 - a[i]);
		ans2 += abs(m2 - a[i]);
	}
	cout<<min(ans1, ans2);
	return 0;
}
