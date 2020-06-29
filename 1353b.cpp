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

ll t,n,k,i,x,sum,j;
vll a,b;

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
		cin>>n>>k;
		a.clear(); b.clear();
		for(i=0;i<n;i++)
		{
			cin>>x;
			a.pb(x);
		}
		for(i=0;i<n;i++)
		{
			cin>>x;
			b.pb(x);
		}
		sort(b.begin(),b.end());
		for(i=n-1,j=k;i>=0,j>0;i--,j--)
		{
			a.pb(b[i]);
		}
		sort(a.begin(),a.end());
		sum=0;
		for(i=n+k-1;i>k-1;i--) sum+=a[i];
		cout<<sum<<"\n";
	}
	return 0;
}