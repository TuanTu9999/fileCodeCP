#include <bits/stdc++.h>

using namespace std;

const int maxn = 21;
int n;
long long a[maxn], k;

bool iSS(int n, long long tar){
    if(tar == 0) return true;
    if(tar < 0 || n < 0) return false;
    return (iSS(n - 1, tar - a[n]) || iSS(n - 1, tar));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(iSS(n, k)) cout << "YES";
    else cout << "NO";
    return 0;
}
