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

string s;
int n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    int t; cin>>t;
    while(t--){
        cin>>n>>s;
        int a, b, c, d;
        a = b = c = d = 0;
        for(char x : s){
            if(x == 'A') a++;
            else if(x == 'B') b++;
            else if(x == 'C') c++;
            else if(x == 'D') d++;
        }
        cout<<min(n, a) + min(n, b) + min(n, c) + min(n, d)<<'\n';
    }
    return 0;
}
