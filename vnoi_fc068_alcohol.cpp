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

set<string> c;
int ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    c.insert("ABSINTH");
    c.insert("TEQUILA");
    c.insert("VODKA");
    c.insert("WHISKEY");
    c.insert("WINE");
    c.insert("BEER");
    c.insert("CHAMPAGNE");
    c.insert("GIN");
    c.insert("RUM");
    c.insert("SAKE");
    c.insert("BRANDY");
    int n; cin>>n;
    while(n--){
        string s; cin>>s;
        if(isdigit(s[0]) && stoi(s) < 18) ans++;
        else if(c.find(s) != c.end()) ans++;
    }
    cout<<ans;
    return 0;
}
