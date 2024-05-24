#include <bits/stdc++.h>
#define lli long long int
 
using namespace std;
const int maxn = 1e6 + 9;
const int mod = 1e9 + 7;
lli dp[maxn][3];
 
 
 
int main()
{
    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i < maxn; i++)
        {
        dp[i][1] = (dp[i-1][1]*4%mod + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2]*2%mod)%mod;
    }
 
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<(dp[n][1] + dp[n][2])%mod<<endl;
    }
 
}
