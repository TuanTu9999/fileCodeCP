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

const int maxn = 1e7 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, k, ans, l[maxn], d[maxn];
pii a[maxn];
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n >> k >> s;
	for(int i = 0; i < n; i++){
		if(s[i] == 'L') a[i].first = 0;
		else if(s[i] == 'Q') a[i].first = 1;
		else a[i].first = 2;
		a[i].second = i;
	}
	sort(a, a + n);
	// for(int i = 0; i < n; i++){
	// 	cout<<a[i].first<<' '<<a[i].second<<'\n';
	// }
	for(int i = 0, cntL = 0, cntD = 0; i < n; i++){
		cntL += (s[i] == 'L');
		cntD += (s[i] == 'D');
		if(cntL >= k) l[i] = i - cntL + 1;
		else l[i] = -1;
		if(cntD >= k) d[i] = i - cntD + 1;
		else d[i] = -1;
	}
	for(int i = 0; i < n; i++) cout<<l[i]<<' ';
	el;
	for(int i = 0; i < n; i++) cout<<d[i]<<' ';
	el;
	cout<<ans;
	return 0;
}