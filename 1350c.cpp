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

ll n,i,a[MAX],j,ans,prod,gcd,lcm,len;
map<ll,ll>m;
vll v;

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
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				m[j]++;
				if(j*j!=a[i]) m[a[i]/j]++;
			}
		}
	}

	for(auto it:m)
	{
		if(it.second>=n-1 && it.first>1)
		{
			v.pb(it.first);
		}
	}

	ll len = v.size();
	if(!len)
	{
		cout<<"1"; return 0;
	}
	prod=v[0]; gcd=v[0]; lcm=v[0];
	for(i=1;i<len;i++)
	{
		prod = prod*v[i];
		gcd = __gcd(gcd,v[i]);
		lcm = prod/gcd;
		prod = lcm; gcd=lcm;	
	}
	cout<<lcm;
	return 0;
}