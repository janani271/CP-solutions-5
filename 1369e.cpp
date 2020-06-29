#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,m,i,plates[MAX],x[MAX],y[MAX],cnt[MAX],visited[MAX],cur,opp;
unordered_set<ll>likes[MAX];
queue<ll>q;
vll ans;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>plates[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
		cnt[x[i]]++; cnt[y[i]]++;
		likes[x[i]].insert(i);
		likes[y[i]].insert(i);
	}
	for(i=1;i<=n;i++)
	{
		if(plates[i]-cnt[i] >=0)
		{
			q.push(i);
			visited[i]=1;
		}
	}

	while(!q.empty())
	{
		cur = q.front(); q.pop();
		for(auto it:likes[cur]) ans.push_back(it);

		for(auto it:likes[cur])
		{
			opp = cur ^ (x[it]^y[it]);
			likes[opp].erase(it);
			cnt[opp]--;
			if(plates[opp]>=cnt[opp] && !visited[opp])
			{
				visited[opp]=1;
				q.push(opp);
			}
		}
	}

	
	if(ans.size()!=m)
	{
		cout<<"DEAD";
		return 0;
	}
	
	cout<<"ALIVE\n";
	reverse(ans.begin(),ans.end());
	for(auto it:ans) cout<<it<<" ";

	return 0;
}