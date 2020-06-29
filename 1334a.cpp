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
ll t,n,play,clrs,p[MAX],c[MAX],i,flag;
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
		play=0;
		clrs=0;
		p[0]=0; c[0]=0; flag=1;
		for(i=1;i<=n;i++)
		{
			cin>>p[i]>>c[i];
			if(p[i]<p[i-1] || c[i]<c[i-1] || p[i]<c[i] || p[i]-p[i-1]<c[i]-c[i-1]) flag=0;
			else
			{
				// cout<<"YES\n";
				// play += p[i];
				// clrs += c[i];
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}