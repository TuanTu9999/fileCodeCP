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
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>t;
	while(t--){
		cin>>s;
		int res = 0;
		for(char x : s){
			if(x == 'u' || x == 'e' || x == 'o' || x == 'a' || x == 'i') res++;
		}
		if(res) cout<<"Zinno\n";
		else cout<<"Quocsensei\n";
	}
	return 0;
}