#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 3;
const int INF = 1e9;
vector<int> cp;
int n, a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 0; i * i <= INF; i++){
        if(!binary_search(a + 1, a + n + 1, i * i)){
            cout << i * i;
            break;
        }
    }
    return 0;
}
