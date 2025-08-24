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

int t, n, c1[30], c2[30];
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> t;
	while(t--){
		memset(c1, 0, sizeof c1);
		memset(c2, 0, sizeof c2);
		cin >> n >> s;
		int ans = 0;
		
		for(int i = 0; i < n; i++){
			if(i & 1) c2[(int)s[i] - (int)'a']++;
			else c1[(int)s[i] - (int)'a']++;
		}
		if(n & 1){
			ans++;
			n--;
		}
		ans += n - *max_element(c1, c1 + 30) - *max_element(c2, c2 + 30);
		cout << ans << '\n';
	}
	return 0;
}