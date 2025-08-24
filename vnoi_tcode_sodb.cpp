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

llong l, r, ans, tmp;
bool kt[maxn];
veci nt;

void init(int n){
    for(int i = 2; i * i <= n; i++)
        if(!kt[i]) for(int j = i * i; j <= n; j += i) kt[j] = 1;
    for(int i = 2; i <= n; i++) if(!kt[i]) nt.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    init(1e6);
    cin>>l>>r;
    for(int x : nt){
        tmp = x;
        for(int j = 2; j < 40; j++){
            tmp *= x;
            if(tmp < l) continue;
            if(tmp > r) break;
            if(!kt[j + 1]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
