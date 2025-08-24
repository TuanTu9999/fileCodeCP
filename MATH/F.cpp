#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 3;
int n, a[maxn], cnt, ans;
char tar;
string s;
bool kt[maxn + 2];
vector<int> prime;

void sieve(int n){
    for(int i = 2; i * i <= n; i++){
        if(!kt[i]){
            for(int j = i * i; j <= n; j += i) kt[j] = 1;
        }
    }
    for(int i = 2; i <= n; i++) if(!kt[i]) prime.push_back(i);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> tar;
    sieve(n + 3);
    for(int i = 1; i <= n; i++) cin >> a[i];
    cin >> s;
    for(int pos : prime){
        if(pos > n) break;
        if(s[pos - 1] == tar) ans = max(ans, a[pos]);
    }
    for(int pos : prime){
        if(pos > n) break;
        if(s[pos - 1] == tar && a[pos] == ans) cnt++;
    }

    cout << cnt << ' ' << ans;
    return 0;
}
