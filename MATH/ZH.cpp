#include <bits/stdc++.h>

using namespace std;

bool kt[(int)2e7 + 3];

void sieve(){
    int n = 2e7;
    for(int i = 2; i * i <= n; i++){
        if(!kt[i]){
            for(int j = i * i; j <= n; j += i) kt[j] = 1;
        }
    }
}

int t, n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    sieve();
    cin >> t;
    while(t--){
        cin >> n;
        if(n < 5 || kt[n]){
            cout << "NO\n";
            continue;
        }
        int L, R;
        L = R = n;
        L--;
        R++;
        while(kt[L]) L--;
        while(kt[R]) R++;
        if((L + R) % 2 == 0 && 2 * n == L + R) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
