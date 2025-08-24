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
const int oo = 1e6;
const long long ool = 1e18;
#define FILENAME ""

int n, t, pos = 10;;
llong a[maxn];

void init(){
	for(int i = 1; i < 10; i++) a[i] = i;

	for(int i = 10; i < 100; i += 10) a[pos++] = i;
	for(int i = 100; i < 1000; i += 100) a[pos++] = i;
	for(int i = 1000; i < 10000; i += 1000) a[pos++] = i;
	for(int i = 10000; i < 100000; i += 10000) a[pos++] = i;
	for(int i = 100000; i < 1000000; i += 100000) a[pos++] = i;
	a[pos++] = 1000000;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	init();
	cin >> t;
	while(t--){
		cin >> n;
		int id = upper_bound(a, a + pos, n) - a - 1;
		cout << id << '\n';
	}
	return 0;
}