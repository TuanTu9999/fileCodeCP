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

llong f[100];
int id = 2;

void init(){
	f[1] = 1;
	for(int i = 2; i <= 93; i++, id++){
		f[i] = f[i - 1] + f[i - 2];
		if(f[i] > ooi) break;
	}
}

int n, t;

bool check(int a){
	if(a == 0) return true;
	for(int i = 1; i <= id; i++){
		if(f[i] > a) return false;
		if(a % f[i] == 0 && binary_search(f + 1, f + id + 1, a / f[i])) return true;
	}
	return false;
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
		if(check(n)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}