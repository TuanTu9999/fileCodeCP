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

int t;
string s, a;

void sol(){
    cin>>s>>a;
    int n = s.size(), m = a.size(), j = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == a[j] && j < m) j++;
        else if(s[i] == '?' && j < m){
            s[i] = a[j];
            j++;
        }
    }
    if(j >= m){
        cout<<"YES\n";
        for(int i = 0; i < n; i++) if(s[i] == '?') s[i] = 'a';
        cout<<s<<'\n';
    }
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>t;
    while(t--) sol();
    return 0;
}
