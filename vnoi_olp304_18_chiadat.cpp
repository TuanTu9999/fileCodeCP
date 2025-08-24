#include <bits/stdc++.h>
#define llong            long long
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define fastio           ios_base::sync_with_stdio(0); cin.tie(0);
#define fin(NAME)        freopen(NAME".INP", "r", stdin)
#define fou(NAME)        freopen(NAME".OUT", "w", stdout)
#define ld               long double
#define sz(a)            sizeof a
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back
#define mp               make_pair
#define BIT(n)           (1 << n)
#define bit(mask, i)     ((mask >> i) & 1)
#define set_on(mask, i)  (mask | BIT(i))
#define set_off(mask, i) (mask & ~BIT(i))
#define all(v)           v.begin(), v.end()
#define reset(a)         memset(a, 0, sizeof a)
#define fileio(f)        fin(f); fou(f);

using namespace std;

const int maxn = 500 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;

//link: https://oj.vnoi.info/problem/olp304_18_chiadat
int n, x, ans = ooi, s[maxn][maxn], s1, s2, s3, s4;

int get(int u1, int u2, int v1, int v2){
	return s[u2][v2] - s[u1 - 1][v2] - s[u2][v1 - 1] + s[u1 - 1][v1 - 1];
}

int main(){
	fastio;
	fileio("chiadat");
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>x;
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= n; j++){
			s1 = get(1, i, 1, j); // Tổng số cây gỗ quý ở góc phần tư trên bên trái
            s2 = get(i + 1, n, 1, j); // Tổng số cây gỗ quý ở góc phần tư dưới bên trái
            s3 = get(1, i, j + 1, n); // Tổng số cây gỗ quý ở góc phần tư trên bên phải
            s4 = get(i + 1, n, j + 1, n); // Tổng số cây gỗ quý ở góc phần tư dưới bên phải
			ans = min(ans, max({s1, s2, s3, s4}) - min({s1, s2, s3, s4}));
		}
	}
	cout<<ans;
	cerr<<"\nRUN TIME: "; cerr<<(1.0*clock()/CLOCKS_PER_SEC)<<'\n';
	return 0;
}