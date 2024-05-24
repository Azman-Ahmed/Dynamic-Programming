#include <bits/stdc++.h>
#define lli long long int
 
using namespace std;
 
lli dp[1000005];
 
const int MOD = (int)1e9 + 7;
 
int main() {
	lli n, x;
	cin >> n >> x;
	vector<lli> veca(n);
	for (lli i = 0; i < n; i++) cin >> veca[i];
	for (lli i = 0; i <= x; i++) dp[i] = INT_MAX;
	dp[0] = 0;
	for (lli i = 1; i <= n; i++)
    {
		for (lli j = 0; j <= x; j++)
		{
			if (j - veca[i - 1] >= 0)
			{
				dp[j] = min(dp[j], dp[j - veca[i - 1]] + 1);
			}
		}
	}
	cout << (dp[x] >= INT_MAX ? -1 : dp[x]) << '\n';
}