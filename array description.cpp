#include<bits/stdc++.h>
#define ll long long
#define lli long long int
#define forn(n) for(int i = 0; i<n; i++)
#define pr(n) cout<<n<<endl;
#define all(x) (x).begin(), (x).end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
 
using namespace std;
 
lli dp[100001][101];
const lli mod = (10e8) + 7;
 
void solve()
{
    lli n, m;
    cin>>n>>m;
 
    vector<lli> veca(n);
 
    for(lli i=0; i<n; i++) cin>>veca[i];
 
 
 
    if(veca[0]==0)
    {
        for(lli i=0; i<=101; i++)
        {
            dp[0][i] = 1;
        }
    }
    else dp[0][veca[0]] = 1;
 
//    for(int i=0; i<n; i++) cout<<veca[i]<<" ";
 
    for(lli i=1; i<n; i++)
    {
        if(veca[i]==0)
        {
            for(lli j = 1; j<=m; j++)
            {
                dp[i][j] += dp[i-1][j];
                if(j-1>0) dp[i][j]+=dp[i-1][j-1];
                if(j+1<=m) dp[i][j]+=dp[i-1][j+1];
                dp[i][j]%=mod;
            }
        }
        else
        {
            dp[i][veca[i]] += dp[i-1][veca[i]];
            if(veca[i]-1>0) dp[i][veca[i]]+=dp[i-1][veca[i]-1];
            if(veca[i]+1<=m) dp[i][veca[i]]+=dp[i-1][veca[i]+1];
            dp[i][veca[i]]%=mod;
        }
    }
 
    lli ans = 0;
 
    for(lli i=1; i<=m; i++)
    {
        ans+=dp[n-1][i];
        ans%=mod;
    }
    cout<<ans<<endl;
 
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<=m; j++) cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
}
 
int main()
{
    lli t = 1;
//    cin>>t;
    while(t--) solve();
}