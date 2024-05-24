#include <bits/stdc++.h>
#define lli long long int
 
using namespace std;
 
set<lli> s;
 
void solve()
{
    lli n;
    cin>>n;
    vector<lli> veca(n);
    s.insert(0);
    for(lli i=0; i<n; i++)
    {
        cin>>veca[i];
//        s.insert(veca[i]);
    }
    for(lli i=0; i<n; i++)
    {
        set<lli> temp;
        for(auto x:s)
        {
            temp.insert(x+veca[i]);
        }
 
        for(auto x: temp)
        {
            s.insert(x);
        }
    }
 
    cout<<s.size() - 1<<endl;
    for(auto x: s)
    {
        if(x) cout<<x<<" ";
    }
    cout<<endl;
 
 
}
int main()
{
    lli t = 1;
//    cin>>t;
    while(t--) solve();
}