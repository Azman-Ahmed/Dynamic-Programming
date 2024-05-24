#include <bits/stdc++.h>
 
using namespace std;
 
 
 
void solve()
{
    int n,x;
    cin>>n>>x;
    vector<int> price(n), page(n);
 
    vector< vector<int> > dp(n+1, vector<int> (x+1, 0));
 
    for(int i=0; i<n; i++) cin>>price[i];
    for(int i=0; i<n; i++) cin>>page[i];
 
 
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=x; j++)
        {
            dp[i][j] = dp[i-1][j];
 
            if(j >= price[i-1])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-price[i-1]] + page[i-1]);
            }
        }
    }
 
//    for(int i=0; i<=n; i++)
//    {
//        for(int j = 0; j<=x; j++) cout<<dp[i][j]<<" ";
//        cout<<endl;
//    }
    cout<<dp[n][x]<<endl;
 
}
int main()
{
    int t = 1;
//    cin>>t;
    while(t--) solve();
}