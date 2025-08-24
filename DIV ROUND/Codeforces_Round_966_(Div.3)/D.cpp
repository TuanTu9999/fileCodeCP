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

const int maxn = 2e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int t, n;
llong pre[maxn];
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		llong ans = 0;
		memset(pre, 0, sizeof pre);
		cin>>n;
		for(int i = 1; i <= n; i++){
			int x; cin>>x;
			pre[i] = pre[i - 1] + x;
		}
		cin>>s;
		veci left, right;
		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] == 'L') left.push_back(i + 1);
			else right.push_back(i + 1);
		}
		sort(left.begin(), left.end(), greater<int>());
		sort(right.begin(), right.end());
		while(!left.empty() && !right.empty()){
			if(right.back() >= left.back()) ans += pre[right.back()] - pre[left.back() - 1];
			right.pop_back();
			left.pop_back();
		}
		cout<<ans, el;
	}
	return 0;
}