#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

using namespace std;

ll MOD=1e9+7;

ll add(ll a,ll b)
{
	return ((a%MOD) + (b%MOD))%MOD;
}
ll mul(ll a,ll b)
{
	return ((a%MOD) * (b%MOD))%MOD;
}
ll sub(ll a,ll b)
{
	return ((a%MOD) - (b%MOD) + MOD)%MOD;
}
ll t,n,i,a,len,ans,cur,res;
map<ll,ll>m;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>t;
	while(t--)
	{
		cin>>n;
		m.clear();
		for(i=1;i<=n;i++)
		{
			cin>>a;
			m[a]++;
		}
		len = m.size();
		ans=0;
		for(auto it:m)
		{
			cur = it.second;
			res = min(len-1,cur);
			res = max(res,min(len,cur-1));
			ans = max(ans,res);
			// cout<<"cur : "<<cur<<"\tlen : "<<len<<"\n";
			// cout<<"res : "<<res<<"\n\n";
			// cout<<"aha : "<<min(len,cur-1)<<"\n";
		}
		cout<<ans<<"\n";
	}
	return 0;
}