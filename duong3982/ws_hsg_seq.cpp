#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, q, a[maxn], pre[maxn], nex[maxn];
pair<int, int> c[maxn];
stack<int> st;

void init(){
    // build pre
    st.push(0);
    a[0] = 1e9;
    for(int i = 1; i <= n; i++){
        while(a[i] >= a[st.top()])
            st.pop();
        pre[i] = st.top();
        st.push(i);
    }
    while(st.size())
        st.pop();
    // build nex
    st.push(n + 1);
    a[n + 1] = 1e9;
    for(int i = n; i > 0; i--){
        while(a[i] >= a[st.top()])
            st.pop();
        nex[i] = st.top();
        st.push(i);
    }
    for(int i = 1; i <= n; i++)
        c[i] = pair<int, int>(a[i], nex[i] - pre[i] - 1);
    sort(c + 1, c + n + 1);
    for(int i = 2; i <= n; i++)
        c[i] = pair<int, int>(c[i].first, max(c[i].second, c[i - 1].second));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "SEQ"
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    init();
    while(q--){
        int k; cin >> k;
        int pos = upper_bound(c + 1, c + n + 1, pair<int, int>(k, maxn)) - c - 1;
        cout << c[pos].second << '\n';
    }
    return 0;
}
