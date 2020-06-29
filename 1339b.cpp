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
ll t,n,i,a[MAX],k,j;
vll b;
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
		b.clear();
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		k=n-1; j=0;
		for(i=0;i<n;i++)
		{
			if(i%2==0)
			{
				b.pb(a[k]);
				k--;
			}
			else
			{
				b.pb(a[j]);
				j++;
			}
		}
		reverse(b.begin(),b.end());
		for(i=0;i<n;i++) cout<<b[i]<<" ";
			cout<<"\n";
	}
	return 0;
}