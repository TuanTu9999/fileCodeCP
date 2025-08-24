#include <bits/stdc++.h>
#define llong            long long
#define ld 				 long double
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back

using namespace std;

const int maxn = 1e6 + 3;
const ld pi = 3.141592653589793238462643383;
#define FILENAME ""

int a, b;
ld R, n;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> a >> b >> R >> n;
	n *= 100000;
	ld sovong = n / (2.0 * R * pi);
	cout << (int)(sovong * a / b);
	return 0;
}