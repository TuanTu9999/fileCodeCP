#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

int n, x, y, z;
string Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> x >> y >> z;
    int num = 0;
    z = n - x - y;
    while(z--){
        Ans += (char)(num + '0');
        num ^= 1;
    }
    num = 0;
    while(x--){
        Ans += (char)(num + 'A');
        num ^= 1;
    }
    num = 0;
    while(y--){
        Ans += (char)(num + 'a');
        num ^= 1;
    }
    cout << Ans;
    return 0;
}