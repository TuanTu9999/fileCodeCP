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
#define FILENAME "APEASY"

string s, tmp;
int cnt, num1, num2;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen(FILENAME".INP", "r", stdin);
	freopen(FILENAME".OUT", "w", stdout);
	cin>>s;
	for(char x : s){
		if(isdigit(x)) tmp += x;
		else{
			if(!num1) num1 = stoi(tmp);
			tmp = "";
		}
		cnt += (x == '-');
	}
	num2 = stoi(tmp);
	if(cnt & 1) cout<<num1 - num2;
	else cout<<num1 + num2;
	return 0;
}