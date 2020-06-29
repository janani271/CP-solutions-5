#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll n, deg[MAX],node,i,a,b,u,v; 
vector<pairs>e;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	memset(deg,0,sizeof deg);
	node=-1;
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		e.pb({u,v});
		deg[u]++; deg[v]++;
		if(deg[u]==3) node=u;
		else if(deg[v]==3) node=v;
	}
	if(node==-1)
	{
		for(i=0;i<n-1;i++)
			cout<<i<<"\n";
	}
	else
	{
		a=0;b=3;
		for(auto it:e)
		{
			if((it.first==node || it.second==node) && a<3)
				cout<<a++<<"\n";
			else cout<<b++<<"\n";
		}
	}

	return 0;
}