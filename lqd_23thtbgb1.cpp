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
const int ooi = 2e9;
const long long ool = 1e18;
#define FILENAME ""

int a, b, m;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>a>>b;
    if(a < 0 && b > 0) m = 0;
    else if(b <= 0) m = b - 1;
    else if(a >= 0) m = a + 1;
    cout<<m;
    return 0;
}
