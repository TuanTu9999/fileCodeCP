#include <bits/stdc++.h>
#define maxn 210
#define For(i,a,b) for (int i = a; i <= b; i++)
#define Ford(i,a,b) for (int i = a; i >= b; i--)
#define cmax 1000000000

using namespace std;

int n, t, C[maxn], q[maxn], nhom[maxn], d[maxn], dd[maxn];
bool a[maxn][maxn];
bool cx[maxn];
int Dem;

bool check(int k)
{
    For(i,1,n) C[i] = 0;
    Ford(i,n,1)
    {
        int u = q[i], temp = t + 1;
        For (v,1,n)
            if (a[u][v] && nhom[v] < temp) temp = nhom[v];
        temp--;
        while (temp > 0 && C[temp] == k) temp--;
        if (temp == 0) return false;
        nhom[u] = temp;
        C[temp]++;
    }
    return true;
}

void dfs(int u)
{
    cx[u] = true;
    For(i,1,n)
        if (a[u][i] && !cx[i]) dfs(i);
    q[Dem--] = u;
}

void init(){
    t = Dem = 0;
    For(i,1,n){
        C[i] = q[i]=nhom[i]=d[i]=dd[i]=0;
        For(j,1,n)
            a[i][j]=false;
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SCHEDULE.inp","r",stdin);
    freopen("SCHEDULE.out","w",stdout);
    int test;
    cin>>test;
    for (;test>0;test--){
        cin >> n;
        init();
        for (int i = 1; i <= n; i++)
        {
            while(true)
            {
                int x;
                cin >> x;
                if (x == 0) break;
                a[x][i] = true;
            }
        }
        Dem = n;
        For(i,1,n) cx[i] = false;
        For(i,1,n)
            if (!cx[i]) dfs(i);
        For(i,1,n) d[i] = 1;
        For(i,1,n)
            For(j,i+1,n)
            {
                int u = q[i], v = q[j];
                if (a[u][v] && d[v] < d[u] + 1) d[v] = d[u] + 1;
            }
        t = 0;
        For(i,1,n) t = max(t,d[i]);
        For(i,1,n) dd[d[i]]++;
        For (i,2,n) dd[i] = dd[i-1] + dd[i];
        For(i,1,n)
        {
            q[dd[d[i]]] = i;
            dd[d[i]]--;
        }
        int dau = 0, cuoi = n, res = 0;
        while (dau <= cuoi)
        {
            int giua = (dau + cuoi)>>1;
            if (check(giua)) res = giua, cuoi = giua - 1;
            else dau = giua + 1;
        }
        cout << t << " " << res << endl;
    }
    return 0;
}
