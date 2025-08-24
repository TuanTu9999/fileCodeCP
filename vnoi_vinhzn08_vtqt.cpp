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
char a[10][10];

void sol(){
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			cin>>a[i][j];

	for(int x = 0; x < 8; x++){
		for(int y = 0; y < 8; y++){
			if(a[x][y] == 'x' && a[x - 1][y - 1] == 'x' && a[x + 1][y - 1] == 'x'
				&& a[x - 1][y + 1] == 'x' && a[x + 1][y + 1] == 'x'){
				cout<<x + 1<<' '<<y + 1<<'\n';
				return;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin>>t;
	while(t--) sol();
	return 0;
}