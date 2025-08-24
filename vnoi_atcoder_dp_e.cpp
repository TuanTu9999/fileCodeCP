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

const int maxn = 100 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, maxw, w[maxn], v[maxn], sum;
llong f[maxn][(int)1e6 + 3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> maxw;
    for(int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
        sum += v[i];
    }

    for(int i = 0; i <= n; i++) f[i][0] = 0;
    for(int i = 1; i <= sum; i++) f[0][i] = ooi;

    for(int i = 1; i <= n; i++){
        for(int val = 1; val <= sum; val++){
            if(val >= v[i]) 
                f[i][val] = min(f[i - 1][val], f[i - 1][val - v[i]] + w[i]);
            else 
                f[i][val] = f[i - 1][val];
        }
    }

    for(int val = sum; val > 0; val--){
        for(int i = n; i > 0; i--){
            if(f[i][val] <= maxw){
                cout << val;
                return 0;
            }
        }
    }
    return 0;
}
