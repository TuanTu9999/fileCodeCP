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

const int maxn = 1e3 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, pre[maxn][maxn], q;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char x; cin>>x;
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (x == '*');
        }
    }
    while(q--){
        int x1, x2, y1, y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1]<<'\n';
    }
    return 0;
}
