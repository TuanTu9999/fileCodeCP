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

const int maxn = 5e3 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int f[maxn][maxn];
string a, b, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> a >> b;
    int n = a.size(), m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    for(int i = 1; i <= n; i++)
        f[i][0] = f[0][i] = i;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            // if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1];
            // else f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
            int c = (a[i] != b[j]);
            f[i][j] = min({f[i - 1][j] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] + c});
        }
    }
    cout << f[n][m];
    return 0;
}