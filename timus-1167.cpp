#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<string,string> ii;
#define pii 3.141592654
#define INF 1000000007
#define N 505
#define M 305
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sif(x) scanf("%lf",&x)
#define sil(x) scanf("%I64d",&x)
#define pi(x) printf("%d\n",x)
#define pis(x) printf("%d ",x)
#define cpi(x) printf("Case %d: ",x)
#define pil(x) printf("%I64d\n",x)
#define rep(i,n,m) for(int i = n; i< m; i++)
#define reps(i,n,m) for(int i = n; i >= m; i--)
#define lft(x) x*2
#define rgt(x) x*2+1

int n,k,dp[N][N],sum[N];

int go(int pos,int how)
{
    if(how > k) return INF;
    if(pos > n){
        //cout << how << endl;
        if(how == k) return 0;
        else return INF;
    }

    int &ret = dp[pos][how];
    if(ret != -1) return ret;

    ret = INT_MAX;
    for(int i = pos; i <= n; i++){
        int o = sum[i] - sum[pos-1];
        int oo = i - o - pos + 1;
        //cout << i << " " <<pos << " " <<o << " " <<oo << endl;
        ret = min(ret,o*oo + go(i+1,how+1));
    }

    return ret;

}

int main()
{
    si(n);si(k);

    memset(dp,-1,sizeof(dp));

    int x;
    rep(i,1,n+1){
        si(x);
        sum[i] = sum[i-1] + x;
    }

    int ans = go(1,0);

    pi(ans);

	return 0;
}
