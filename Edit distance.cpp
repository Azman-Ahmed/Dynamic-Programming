#include <bits/stdc++.h>
#define lli long long int
 
using namespace std;
 
void solve()
{
  string str1, str2;
  cin>>str1>>str2;
 
  lli n = str1.size();
  lli m = str2.size();
 
  int dp[n+5][m+5];
 
  for(int i=0; i<=n; i++)
  {
    for(int j=0; j<=m; j++)
    {
      dp[i][j] = 1e9;
    }
  }
	dp[0][0] = 0;
  for (int i = 0; i <= str1.size(); i++)
  {
    for (int j = 0; j <= str2.size(); j++)
    {
      if (i != 0) dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + 1);
			if (j != 0) dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + 1);
 
			if (i != 0 && j != 0)
      {
				int tem = dp[i - 1][j - 1] + (str1[i - 1] != str2[j - 1]);
				dp[i][j] = min(dp[i][j], tem);
			}
		}
	}
	cout << dp[str1.size()][str2.size()] << endl;
}
 
int main()
{
    lli t = 1;
//    cin>>t;
    while(t--) solve();
}