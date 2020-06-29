#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }
ll t,n,a,i,pos[MAX],nxt,flag,visited[MAX];
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
		for(i=0;i<n;i++)
		{
			cin>>a;
			pos[a] = i+1;
		}
		nxt = -1;
		flag=1;
		memset(visited,0,sizeof visited);
		visited[n+1]=1;
		for(i=1;i<=n;i++)
		{
			if(nxt==-1)
			{
				if(!visited[pos[i]])
				{
					visited[pos[i]] = 1;
					nxt = pos[i]+1;
					if(visited[nxt]) nxt=-1;
				}
				else
				{
					flag=0; break;
				}
			}
			else
			{
				if(pos[i]==nxt)
				{
					visited[nxt] = 1;
					nxt = pos[i]+1;
					if(visited[nxt]) nxt=-1;
				}
				else
				{
					flag=0; break;
				}
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}