#include <bits/stdc++.h>
#define lli long long int
#define MAXN 1000001
const int mod = 1e9+7;
 
using namespace std;
 
set<lli> s;
 
int dp[MAXN];
 
int calc(int n)
{
    if (dp[n] != 0) return dp[n];
 
    for (int i = 1; i <= 6; i++)
    {
        if (n - i >= 0)
        {
            dp[n] += calc(n - i);
            dp[n] %= mod;
        }
    }
    return dp[n];
}
 
void solve()
{
    lli n;
    cin>>n;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    cout<<calc(n)<<endl;
}
int main()
{
    lli t = 1;
//    cin>>t;
    while(t--) solve();
}