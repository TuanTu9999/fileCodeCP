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
#define FILENAME "OJ"

int n, m, preh[maxn];
llong pre[maxn];
pii a[maxn];
stack<int> st;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i].first; //x
    for(int i = 0; i < n; i++) cin>>a[i].second; //h
    sort(a, a + n);
    pre[0] = 1LL * a[0].first * a[0].second;
    preh[0] = a[0].first;
    st.push(0);
    for(int i = 1; i < n; i++){
        if(a[i].second <= a[i - 1].second)
            pre[i] = pre[i - 1] + 1LL * a[i].second * (a[i].first - a[i - 1].first - 1);
        else{
            while(!st.empty() && a[i].second > a[st.top()].second) st.pop();
            if(st.empty()) pre[i] = 1LL * a[i].first * a[i].second - preh[i - 1];
            else pre[i] = pre[st.top()] + 1LL * a[i].second * (a[i].second - a[st.top()].second - 1) - (preh[i] - preh[st.top() - 1]);
        }
        st.push(a[i].first);
        preh[i] = preh[i - 1] +  a[i].second;
    }
    cin>>m;
    while(m--){
        llong q; cin>>q;
        cout<<lower_bound(pre, pre + n, q) - pre<<'\n';
    }
    return 0;
}
