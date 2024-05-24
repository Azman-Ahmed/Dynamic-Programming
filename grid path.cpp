#include <bits/stdc++.h>
#define lli unsigned long long int
#define mod 1000000007
 
using namespace std;
 
char grid[1005][1005];
lli ans[1005][1005];
 
void solve()
{
  lli n;
  cin>>n;
 
  for(lli i=0; i<n; i++)
  {
    for(lli j=0; j<n; j++) cin>>grid[i][j];
  }
 
  for(lli i=0; i<n; i++)
  {
    for(lli j=0; j<n; j++) ans[i][j] = 0;
  }
 
  for(lli i=0; i<n; i++)
  {
    if(grid[0][i]=='*') break;
    ans[0][i] = 1;
  }
 
  for(lli i=0; i<n; i++)
  {
    if(grid[i][0]=='*') break;
    ans[i][0] = 1;
  }
 
  for(lli i=1; i<n; i++)
  {
    for(lli j=1; j<n; j++)
    {
      if(grid[i][j]=='*') continue;
      ans[i][j] = (ans[i-1][j] + ans[i][j-1] ) % mod;
    }
  }
 
//  for(lli i=0; i<n; i++)
//  {
//    for(lli j=0; j<n; j++) cout<<ans[i][j]<<" ";
//    cout<<endl;
//  }
  cout<<ans[n-1][n-1]<<endl;
 
}
 
int main()
{
  lli t = 1;
//  cin>>t;
 
  while(t--) solve();
}
