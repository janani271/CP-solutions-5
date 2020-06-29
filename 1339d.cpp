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
ll n,i,u,v,mi,mx,visited[MAX],even[MAX],odd[MAX],leaf[MAX];
ll start;
vll g[MAX];
void dfs(ll x)
{
	visited[x]=1;
	ll c=0, v=0;
	for(auto it:g[x])
	{
		if(!visited[it])
		{
			dfs(it);
			v++;
		}
		if(even[it]==1)
			odd[x]=1;
		if(odd[it]==1)
			even[x]=1;
		if(leaf[it])
			c++;
	}
	if(v==0)
	{
		even[x]=1;
		leaf[x]=1;
	}
	if(even[x] && odd[x])
	{
		mi = 3;
	}
	// cout<<"x : "<<x<<"\tc : "<<c<<"\n";
	if(c) mx-=(c-1);
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(i=1;i<=n;i++)
	{
		if(g[i].size()>1)
		{
			start = i;
			break;
		}
	}

	mi=1; mx=n-1;
	dfs(start);
	cout<<mi<<" "<<mx;
	return 0;
}