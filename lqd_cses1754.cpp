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

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int t, a, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>t;
    while(t--){
        cin>>a>>b;
        if((a + b) % 3 == 0
           /*
           kiểm tra xem tổng số đồng xu có thể được chia đều thành các nhóm
           có tổng là 3 hay không, vì mỗi lần loại bỏ tổng cộng
            loại bỏ 3 đồng xu.
            */
            && 2*min(a, b) >= max(a, b)
           /*
            đảm bảo rằng không có cọc nào có số đồng xu quá nhiều so với
            cọc kia đến mức không thể cân bằng được bằng cách loại bỏ.
            */
           ) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
