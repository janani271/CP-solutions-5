#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003

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

ll n,i,a[MAX],u,v,visited[MAX],dp[MAX];
vll g[MAX];

void dfs(ll x)
{
	visited[x]=1;
	dp[x] = a[x];
	for(auto it : g[x])
	{
		if(!visited[it])
		{
			dfs(it);
			dp[x] += max((ll)0,dp[it]);
		}
	}
	// cout<<"x : "<<x<<"\tdp : "<<dp[x]<<"\n";
}

void dfs1(ll x)
{
	visited[x]=1;
	for(auto it:g[x])
	{
		if(visited[it])
		{
			ll temp = dp[it] - max((ll)0,dp[x]);
			dp[x] += max((ll)0,temp);
		}
	}
	for(auto it:g[x])
	{
		if(!visited[it])
			dfs1(it);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0) a[i]=-1;
	}
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		g[u-1].pb(v-1); g[v-1].pb(u-1);
	}
	dfs(0);
	// for(i=0;i<n;i++) cout<<dp[i]<<" ";
	memset(visited,0,sizeof visited);
	dfs1(0);
	for(i=0;i<n;i++) cout<<dp[i]<<" ";
	return 0;
}