#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200005

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll t,n,m,a,b,c,u,v,i,cost[MAX],p[MAX],ans,visited[MAX];
ll dist[MAX][7];
vll g[MAX];


void bfs(ll x,ll cnt)
{
	dist[x][cnt] = 0;
	queue<ll>q;
	q.push(x);
	while(!q.empty())
	{
		ll node = q.front(); q.pop();
		for(auto it:g[node])
		{
			if(dist[it][cnt]==INF)
			{
				dist[it][cnt] = dist[node][cnt]+1;
				q.push(it);
			}
		}
	}
}

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
		for(i=0;i<MAX;i++) g[i].clear();
		cin>>n>>m>>a>>b>>c;
		for(i=1;i<=m;i++)
			cin>>cost[i];
		for(i=1;i<=m;i++)
		{
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		
		for(i=1;i<=n;i++) for(ll j=0;j<=5;j++) dist[i][j] = INF;
		bfs(a,0);
		bfs(b,1);
		bfs(c,2);

		sort(cost+1,cost+m+1);
		p[0] = 0;
		for(i=1;i<=m;i++){
			p[i] = p[i-1] + cost[i];
			// cout<<p[i]<<" ";
		}
		// cout<<"\n";

		ans = INF;
		// cout<<dist[1][0] + dist[1][1] + dist[1][2]<<"\n";
		// cout<<ans<<"\n";
		for(i=1;i<=n;i++)
		{
			ll k = dist[i][0] + dist[i][1] + dist[i][2];
			if(k>m) continue;
			ans = min(ans,p[k] + p[dist[i][1]]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}