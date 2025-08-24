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

int t, n;
llong pre[maxn];
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        llong ans = 0;
        memset(pre, 0, sizeof pre);
        cin>>n;
        for(int i = 1; i <= n; i++){
            int x; cin>>x;
            pre[i] = pre[i - 1] + x;
        }
        cin >> s;
        veci lr_pairs;
        llong total_score = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'L'){
                if(i + 1 < n && s[i + 1] == 'R'){
                    total_score += pre[i + 1] - pre[i];
                    lr_pairs.push_back(pre[i + 2] - pre[i + 1] + pre[i] - pre[i - 1]);
                }
                else{
                    total_score += pre[i + 1] - pre[i];
                    lr_pairs.push_back(pre[n] - pre[i] + pre[i] - pre[i - 1]);
                }
            } 
            else total_score += pre[i + 1] - pre[i];
        }
        sort(lr_pairs.begin(), lr_pairs.end(), greater<int>());
        for(int i = 0; i < min((int)lr_pairs.size(), n/2); i++){
            if (lr_pairs[i] > 0) total_score += lr_pairs[i];
        }
        cout<<total_score, el;
    }
    return 0;
}
