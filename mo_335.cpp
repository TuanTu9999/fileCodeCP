#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn], pre[maxn], nex[maxn];
stack<int> st;
long long Ans = -1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = a[n + 1] = -1e9 - 1;
    st.push(0);
    for(int i = 1; i <= n; i++) {
        while(a[i] <= a[st.top()]) st.pop();
        pre[i] = st.top();
        st.push(i);
    }
    while(st.size()) st.pop();
    st.push(n + 1);
    for(int i = n; i > 0; i--) {
        while(a[i] <= a[st.top()]) st.pop();
        nex[i] = st.top();
        st.push(i);
    }
//    for(int i = 1; i <= n; i++) cout << pre[i] << " ";
//    cout << '\n';
//    for(int i = 1; i <= n; i++) cout << nex[i] << " ";
//    cout << '\n';
    for(int i = 1; i <= n; i++)
        Ans = max(Ans, 1LL * (nex[i] - pre[i] - 1) * a[i]);

    cout << Ans;
    return 0;
}
