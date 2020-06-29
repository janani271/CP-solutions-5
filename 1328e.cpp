#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003

ll MOD=1e9+7;

int n , m , i , j , u , v , t , k , flag , ls , d[MAX] , p[MAX];
int  y , st[MAX] , en[MAX] , a[MAX] , visited[MAX];
vll g[MAX];

void dfs(int x, int par, int depth)
{
	visited[x]=1;
	p[x] = par;
	d[x] = depth;
	st[x] = t++;
	for(auto it:g[x])
	{
		if(!visited[it])
			dfs(it,x,depth+1);
	}
	en[x] = t++;
}


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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	int x;
	cin>>n>>m;
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--; v--;
		g[u].pb(v); g[v].pb(u);
	}
	t=0;
	dfs(0,-1,0);

	for(i=0;i<m;i++)
	{
		cin>>k;
		flag=1;
		ls = 0;
		for(j=0;j<k;j++)
		{
			cin>>a[j];
			a[j]--;
			if(d[a[j]] > d[ls])
				ls = a[j];
		}
		
		for(j=0;j<k;j++)
		{
			if(a[j]!=ls && a[j]!=0)
				a[j] = p[a[j]];
		}
		for(j=0;j<k;j++)
		{
			x = a[j];
			if(x == ls) continue;
			if(!(st[x]<=st[ls] && en[ls]<=en[x]))
			{
				flag = 0;
				break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}