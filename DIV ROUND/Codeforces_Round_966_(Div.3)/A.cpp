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

int t;
string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>s;
		if(s[0] == '1' && s[1] == '0' && s[2] != '0' && ((s.size() <= 3 && s[2] >= '2') || (s.size() > 3))) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}