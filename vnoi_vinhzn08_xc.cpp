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
#define FILENAME "test"

string s;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int q, v;
		q = v = 0;
		for(int i = 1; i < (int)s.size(); i++){
			if(s[i] == s[i - 1] && s[i] == s[i + 1]){
				if(s[i] == 'Q') q++;
				else v++;
			}
		}
		cout<<((q < v) ? "Zinno\n" : "Quoc\n");
	}
	return 0;
}