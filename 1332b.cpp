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
ll prime[MAX], i , t , n , a[MAX], c, j, x,ans[MAX];
map<ll,ll>m;
void sieve()
{
	ll mn = 1;
	prime[1] = 1;
	for(i=2;i<=1000;i++)
	{
		if(!prime[i])
		{
			prime[i]= ++mn;
			for(j=i*i;j<=1000;j+=i)
			{
				prime[j]=i;	
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

	sieve();
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		m.clear();c=0;
		for(i=0;i<n;i++)
		{
			x = prime[a[i]];
			// cout<<"a : "<<a[i]<<"\tx : "<<x<<"\n";
			if(m[x]==0)
			{
				m[x] = ++c;
			}
			ans[i] = m[x];
		}
		cout<<c<<"\n";
		for(i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}