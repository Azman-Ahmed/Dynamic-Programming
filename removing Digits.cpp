#include<bits/stdc++.h>
#define ll long long
#define lli long long int
#define forn(n) for(int i = 0; i<n; i++)
#define pr(n) cout<<n<<endl;
#define all(x) (x).begin(), (x).end()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
 
using namespace std;
 
int dp[1000005];
 
void solve()
{
    int n;
    cin>>n;
 
 
    for(int i=0; i<1000005; i++) dp[i] = 1e8;
 
    for(int i=1; i<10; i++)
    {
        dp[i] = 1;
    }
 
 
    for(int i=10; i<1000005; i++)
    {
        int number = i;
        while(number>0)
        {
            int tem1 = number%10;
            number/=10;
            tem1 = i - tem1;
            dp[i] = min(dp[i], dp[tem1] + 1);
        }
    }
 
    cout<<dp[n]<<endl;
}
 
int main()
{
    lli t = 1;
//    cin>>t;
    while(t--) solve();
}