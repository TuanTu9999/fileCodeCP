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

int t, n;
string s;

bool check(){
    int len = sqrt(n);
    if(len * len != n) return false;
    
    for(int i = 0; i < len; i++)
        if(s[i] != '1' || s[(len - 1)*len + i] != '1' ||
         s[i*len] != '1' || s[i*len + (len - 1)] != '1')
            return false;
    
    for(int i = 1; i < len - 1; i++)
        for(int j = 1; j < len - 1; j++)
            if(s[i*len + j] != '0') 
                return false;
    
    return true; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> t;
    while(t--){
        cin >> n >> s;

        if(check()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}