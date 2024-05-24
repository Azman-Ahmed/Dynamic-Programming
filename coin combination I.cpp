#include <bits/stdc++.h>
#define lli long long int
using namespace std;
 
 
lli dp[1000009];
 
const int MOD = 1e9 + 7;
 
int main()
{
	int n, x;
	cin>>n>>x;
 
	vector<int> veca(n);
	for (int i = 0; i < n; i++) cin>>veca[i];
 
 
	dp[0] = 1;
	for (int i = 0; i <= x; i++)
    {
		for (int j = 0; j < n; j++)
		{
			if (i - veca[j] >= 0)
			{
				dp[i] += dp[i - veca[j]];
				dp[i] %= MOD;
			}
		}
	}
 
	cout<<dp[x]<<endl;
}