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

const int maxn = 3e3 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int f[maxn][maxn], n, m;
string s, t, ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(s[i] == t[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}
	int i = n, j = m;
	while(i > 0 && j > 0){
		if(s[i] == t[j]){
			ans = s[i] + ans;
			i--;
			j--;
		}
		else if(f[i][j] == f[i - 1][j]) i--;
		else j--;
	}

	cout << ans;
	return 0;
}