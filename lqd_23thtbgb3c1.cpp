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

int n, k, ans = 1e9, l, r;
veci nexL(maxn), nexQ(maxn), nexD(maxn);
string s;

void init(veci& ans, char target, int k){
	int l = 0, cnt = 0;
	for(int r = 0; r < n; r++){
		cnt += (s[r] == target);
		while(cnt >= k && l < n){
			ans[l] = r;
			cnt -= (s[l] == target);
			l++;
		}
	}
	while(l <= n) ans[l++] = n; 
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>n>>k>>s;
	init(nexL, 'L', k); 
	init(nexQ, 'Q', k); 
	init(nexD, 'D', k);
	for(int i = 0; i < n; i++){
		int l = nexL[i], r = l;
		r = nexQ[r];
		r = nexD[r];
		if(r - l + 1 < 3 * k || r >= n) break;
		ans = min(ans, r - i + 1 - 3 * k);
	}
	if(ans == (int)1e9) cout<<"-1";
	else cout<<ans;
	return 0;
}