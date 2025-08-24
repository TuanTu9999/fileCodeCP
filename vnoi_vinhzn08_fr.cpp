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

const int maxn = 1e4 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME "TUDEPZAI"

int n, k, a[maxn];
llong ans;
vector<pii> memo;

void sm_can_cua_hang(){
	int ma = -1e9;
	for(int i = 0; i < k; i++){
		ma = max({ma, 0, a[i] - i});
	}
	memo.push_back({ma, k});
}

bool check(llong mid){
	for(pii x : memo){
		if(mid > x.first){
			mid += x.second;
		}
		else return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>n;
	while(n--){
		cin>>k;
		for(int i = 0; i < k; i++) cin>>a[i];
		sm_can_cua_hang();
	}
	sort(memo.begin(), memo.end());
	int l = 0, r = 2e9;
	while(l <= r){
		llong mid = l + (r - l) / 2;
		if(check(mid)){
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout<<ans;
	return 0;
}