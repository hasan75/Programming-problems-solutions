//////////////////////////////////////
//           Author : Hasan         //
//              CSE,BUET            //
//////////////////////////////////////
#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;



#define ll long long
#define N 105
#define M 1005
#define pb push_back
#define mp make_pair
#define rep(i,n,m) for(int i = n; i < m; i++)
#define reps(i,n,m) for(int i = n;i >= m; i--)
#define sc scanf
#define pc printf


int dp[N][N][N],n,m;
string s[N];
bool vis[N][N][N];

bool check(int r1,int c1,int r2,int c2){
    return r1 >= 0 && r1 < n && c1 >= 0 && c1 < m && r2 >= 0 && r2 < n && c2 >= 0 && c2 < m  ;
}

int go(int r1,int c1,int r2)
{
    int c2 = (r1+c1)-r2; //because both person1 and person2 must go same distance at any given time

    if(!check(r1,c1,r2,c2) || s[r1][c1] == '#' || s[r2][c2] == '#') return -1e6;

    if(r1 == n-1 && c1 == m - 1 && r2 == n-1){
        if(s[r1][c1] == '*') return 1;
        else return 0;
    }

    bool isVis = vis[r1][c1][r2];
    if(isVis) return dp[r1][c1][r2];
    vis[r1][c1][r2] = true;
    int &ret = dp[r1][c1][r2];
    ret = 0;
    int cnt = 0;
    if(s[r1][c1] == '*') cnt++;
    if(s[r2][c2] == '*') cnt++;
    if(r1 == r2 && c1 == c2){
        if(s[r1][c1] == '*') cnt = 1;
        else cnt = 0;
    }

    int a = go(r1+1,c1,r2);//1st down ,2nd right
    int b = go(r1+1,c1,r2+1);//1st down ,2nd down
    int c = go(r1,c1+1,r2);//1st right ,2nd down
    int d = go(r1,c1+1,r2+1);//1st right ,2nd right


    ret = cnt + max(max(a,b),max(c,d));

    return ret;


}




int main()
{


    int t;

    sc("%d",&t);

    while(t--){

        rep(i,0,N){
            rep(j,0,N){
                rep(k,0,N){
                    vis[i][j][k] = 0;
                    dp[i][j][k] = 0;
                }
            }
        }

        sc("%d%d",&m,&n);
        rep(i,0,n) cin >> s[i];
        pc("%d\n",go(0,0,0));



    }



    return 0;
}
