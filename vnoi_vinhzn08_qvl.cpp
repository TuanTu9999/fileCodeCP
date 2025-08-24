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

int n, a[maxn];
llong quoc, lan;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>n;
	for(int i = 0; i < n; i++) cin>>a[i];
	int l = 0, r = n - 1;
	while(l <= r){
		if(a[l] < a[r]){
			quoc += a[r];
			r--;
			if(l > r) break;
		}
		else{
			quoc += a[l];
			l++;
			if(l > r) break;
		}
		if(a[l] < a[r]){
			lan += a[r];
			r--;
			if(l > r) break;
		}
		else{
			lan += a[l];
			l++;
			if(l > r) break;
		}
	}
	cout<<quoc<<' '<<lan;
	return 0;
}