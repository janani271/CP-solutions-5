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

ll n,m,k,p[MAX],q[MAX],ca[MAX],cb[MAX],i,j,a,b,c,x,y;
map<ll,ll>ms;
vector<pairs>v;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	cin>>n>>m>>k;
	p[0]=0;q[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a!=0)
		p[i] = p[i-1] + a;
		else p[i]=0;
	}
	for(j=1;j<=m;j++)
	{
		cin>>b;
		if(b!=0)
		q[j] = q[j-1] + b;
		else q[j]=0;
	}

	c=0;
	for(i=1;i*i<=k;i++)
	{
		if(k%i==0)
		{
			j=k/i;
			if(i<=40000 && j<=40000)
				v.pb({i,j});
			c++;
		}
	}

	for(auto it:v)
	{
		x = it.first;
		y = it.second;
		if(!ms[x])
		{
			ms[x]=1;
			for(i=1;i<=n;i++)
			{
				if(p[i]>=x)
					ca[x]++;
			}
			for(i=1;i<=m;i++)
			{
				if(q[i]>=x)
					cb[x]++;
			}
		}
		if(!ms[y])
		{
			ms[y]=1;
			for(i=1;i<=n;i++)
			{
				if(p[i]>=y)
					ca[y]++;
			}
			for(i=1;i<=m;i++)
			{
				if(q[i]>=y)
					cb[y]++;
			}
		}
	}

	ll res=0;
	for(auto it:v)
	{
		x = it.first;
		y=it.second;

		// cout<<"x : "<<x<<"\ty : "<<y<<"\n";
		// cout<<"x : ca : "<<ca[x]<<"\tcb : "<<cb[y]<<"\n";
		// cout<<"y : ca : "<<ca[y]<<"\tcb : "<<cb[x]<<"\n";
		res += (ca[x]*cb[y]);
		if(x!=y) res += (ca[y]*cb[x]);
	}
	cout<<res;
	return 0;
}