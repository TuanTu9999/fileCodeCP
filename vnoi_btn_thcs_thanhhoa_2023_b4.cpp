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

const int maxn = 3e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, a[maxn];
llong ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>n;
	for(int i = 1; i <= n; i++){
		int x;
		cin>>a[i]>>x;
	}
	sort(a + 1, a + n + 1);
	a[0] = a[1] - 1;
	a[n + 1] = a[n] + 1;
	int d = 1;
	for(int i = 1; i <= n + 1; i++){
		if(a[i] == a[i - 1]) d++;
		else{
			ans += 1LL * d * (d - 1) / 2;
			d = 1;
		}
	}
	cout<<ans;
	return 0;
}