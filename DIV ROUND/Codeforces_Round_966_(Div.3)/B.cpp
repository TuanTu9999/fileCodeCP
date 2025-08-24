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

int t, n, a[maxn];
bool check[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0; i < n; i++) cin>>a[i];
		for(int i = 0; i <= n + 1; i++) check[i] = 0;
		bool res = 1;
		check[a[0]] = 1;
		for(int i = 1; i < n; i++){
			if(!check[a[i] + 1] && !check[a[i] - 1]){
				cout<<"NO\n";
				res = 0;
				break;
			}
			check[a[i]] = 1;
		}
		if(res) cout<<"YES\n";
	}
	return 0;
}