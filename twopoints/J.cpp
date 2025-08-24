#include <bits/stdc++.h>

using namespace std;

const int maxn = 1.5e6 + 3;

int n, m, a[maxn], c[maxn];
set<int> se;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ln = *max_element(a + 1, a + n + 1);
    for(int i = 1; i <= m; i++) c[a[i]]++;
    for(int i = 0; i <= ln + 1; i++) if(c[i] == 0) se.insert(i);
    cout << *(se.begin()) << ' ';
    for(int i = m + 1; i <= n; i++){
        auto it = se.find(a[i]);
        c[a[i]]++;
        if(it != se.end()) se.erase(it);
        c[a[i - m]]--;
        if(c[a[i - m]] == 0) se.insert(a[i - m]);
        cout << *(se.begin()) << ' ';
    }
    return 0;
}
