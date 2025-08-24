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

const int maxn = 2e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, x;
pii a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>x;
    for(int i = 0; i < n; i++){
        cin>>a[i].first;
        a[i].second = i + 1;
    }
    sort(a, a + n);
    int l = 0, r = n - 1;
    while(l < r){
        if(a[l].first + a[r].first ==  x){
            cout<<min(a[l].second, a[r].second)<<' '<<max(a[l].second, a[r].second);
            return 0;
        }
        else if(a[l].first + a[r].first > x) r--;
        else l++;
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
