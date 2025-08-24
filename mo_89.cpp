#include <bits/stdc++.h>

using namespace std;


const int maxn = 30;
long long k, scs[maxn], f[maxn], p[maxn];
// p[i] = 10 ^ i

void init(){
    p[0] = 1;
    for(int i = 1; i <= 18; i++)
        p[i] = p[i - 1] * 10LL;
    for(int x = 1; x <= 18; x++)
        f[x] = 9LL * x * p[x - 1];
    for(int i = 1; i <= 18; i++)
        scs[i] = scs[i - 1] + f[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME "WS"
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> k;
    init();
    // tìm số lượng chữ số của số chứa số thứ k
    int x = lower_bound(scs + 1, scs + 19, k) - scs;
    // vị trí của số thứ k trong tập những số có x chữ số
    long long tmp = k - scs[x - 1] - 1;
    // số chứa chữ số thứ k
    long long num = tmp / x + p[x - 1];
    // vị trí của chữ số thứ k trong số chứa nó (num)
    int pos = tmp % x;
    // chuyển thành string để dễ lấy chữ số thứ k hơn
    string number = to_string(num);
    cout << number[pos];
    return 0;
}
