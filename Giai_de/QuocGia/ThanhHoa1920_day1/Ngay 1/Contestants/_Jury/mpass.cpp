#include <bits/stdc++.h>
#define NAME "mpass."
using namespace std;
ifstream fi (NAME"inp");
ofstream fo (NAME"out");
uint64_t pp,ans,k;
int n,mp,md,lk;
vector<int>a,b,c;

void calc_pr(int x)
{int t,tg;
    mp=0; t=2;
    while(t*t<=x)
    {
        if(x%t==0)
        {
            tg=0;
            while(x%t==0)x/=t, ++tg;
            a.push_back(t);b.push_back(tg);
            ++mp;
        }
        ++t;
    }
    if(x>1)
    {
        a.push_back(x);b.push_back(1);++mp;
    }
}

void calc_dv(int x)
{int t,tmd,tg;
    md=1;c.push_back(1);
    t=1;
    for(int i=0;i<mp;++i)
    {
        tg=1;
        for(int j=1;j<=b[i];++j)
        {
            tg*=a[i];
            for(int it=0;it<md;++it)c.push_back(c[it]*tg);
        }
        md*=(b[i]+1);
    }

    sort(c.begin(),c.end());
}

int64_t calc_pw1(int u)
{int64_t tx,ty,tr;
    tx=1,ty=10; if(u&1)tr=1;else tr=0; u>>=1;
    while(u)
    {
        tx=(tx*ty+tx)%pp;
        ty=ty*ty%pp;
        if(u&1)tr=(tr*ty+tx)%pp;
        u>>=1;
    }
    return tr;
}

int64_t calc_pw(int64_t x,int u,int64_t v)
{int64_t tg,tr;
    tg=x; tr=1;
    while(u)
    {
        if(u&1)tr=(tr*tg)%v;
        tg=(tg*tg)%v;
        u>>=1;
    }
    return tr;
}
// ------------------------------------

int check_k(int x,int ii)
{int t;
 uint64_t tg,r,tr,q;
    t=c[ii];q=(uint64_t)x;
    tg=10; r=1;
    while(t)
    {
       if(t&1)r=(r*tg)%q;
       tg=(tg*tg)%q;
       t>>=1;
    }
    if((r-1)%q==0) return c[ii];
        else return 0;
}

void get_ans(int y)
{int t;
 uint64_t tg,r,tr,q;
    t=y;
    ans=calc_pw1(t);
    ans=(ans*calc_pw((int64_t)k,(int)pp-2,pp))%pp;
}

void calc_ans(int64_t x)
 {int t;
     t=x; lk=0;
     while(t>0){++lk;t/=10;}
     a.clear(); b.clear();c.clear();
     calc_pr(x-1);
     calc_dv(x-1);
     for(int i=1;i<md;++i)
     {
         if(lk<=c[i]) t=check_k(x,i);
         if(t>0){get_ans(t); fo<<ans<<'\n';return;}
     }
 }

int main()
{
    fi>>n;
    pp=1000000007;
    for(int j=1;j<=n;++j)
    {
        fi>>k;
        if(k<10)fo<<"1\n";
          else calc_ans(k);
    }

}
