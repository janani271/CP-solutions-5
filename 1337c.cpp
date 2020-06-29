#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003
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

ll n,k,u,v,visited[MAX],res=0,i,s[MAX],d[MAX];
vll g[MAX];
vll ans;

void dfs(ll x, ll depth)
{
	visited[x]=1;
	d[x] = depth+1;
	s[x]=1;
	for(auto it:g[x])
	{
		if(visited[it]) continue;
		dfs(it,d[x]);
		s[x] += s[it];
	}
	ans.pb(s[x]-d[x]);
	// cout<<s[x]-d[x]<<"\n";
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>k;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	sort(ans.begin(),ans.end(),greater<ll>());
	for(i=0;i<n-k;i++)
	{
		res += ans[i];
	}
	cout<<res;
	return 0;
}