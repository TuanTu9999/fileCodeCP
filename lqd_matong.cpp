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

const int maxn = 1e7 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

llong demuoc(int a){
    llong cnt = 1;
    for(int i = 2; i * i <= a; i++){
        int d = 0;
        while(a % i == 0){
            a /= i;
            d++;
        }
        cnt *= (d + 1);
    }
    if(a > 1) cnt *= 2;
    return cnt;
}

llong ans, f1[maxn];
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    while(n--){
        int a; cin>>a;
        if(a < maxn){
            if(!f1[a]) f1[a] = demuoc(a);
            ans += a * f1[a];
        }
        else{
            ans += a * demuoc(a);
        }
    }
    cout<<ans;
    return 0;
}
