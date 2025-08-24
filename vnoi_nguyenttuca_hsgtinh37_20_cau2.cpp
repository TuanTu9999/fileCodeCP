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
#define FILENAME "KiTuChung"

string a, b;
bool c1[260], c2[260];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> a >> b;
	for(char x : a) c1[(int)x] = 1;
	for(char x : b) c2[(int)x] = 1;
	for(int i = 1; i <= 256; i++) if(c1[i] && c2[i]) cout << (char)i << '\n';
	return 0;
}