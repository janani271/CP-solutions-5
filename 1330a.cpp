#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 1000
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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll t,n,x,i,c[MAX],a,ans,temp;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		memset(c,0,sizeof c);
		for(i=0;i<n;i++)
		{
			cin>>a;
			c[a]=1;
		}
		i=1;temp=x;
		while(temp>=0)
		{
			if(c[i]==0)
			{
				temp--;
			}
			if(temp==-1)
			{
				ans = i-1;
				break;
			}
			i++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}