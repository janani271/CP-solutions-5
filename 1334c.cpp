#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 300003
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
ll t,n,ans,i,a[MAX],k[MAX],res,cur,b[MAX];
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
		ans=0; res=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			ans += a[i];
		}
		a[0] = a[n]; b[0]=b[n];
		for(i=1;i<=n;i++)
		{
			k[i] = max((ll)0 , a[i] - b[i-1]);
			// cout<<"i : "<<k[i]<<"\n";
			res += k[i];
		}
		// cout<<"res : "<<res<<"\n";
		for(i=1;i<=n;i++)
		{
			// cout<<"i diff : "<<a[i]-k[i]<<"\n";
			cur = res + a[i]-k[i]; 
			ans = min(ans,cur);
		}
		cout<<ans<<"\n";	
	}
	return 0;
}