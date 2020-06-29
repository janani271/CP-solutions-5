#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 300009
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

ll t,n,x,cnt,res,i,a[MAX];
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
		cin>>n>>x;
		cnt=0; res=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(i=n;i>=1;i--)
		{
			if(a[i]>=x)
			{
				res += (a[i]-x);
				cnt++;
			}
			if(a[i]<x)
			{
				if(res >= x-a[i])
				{
					cnt++;
					res -= (x-a[i]);
				}
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}