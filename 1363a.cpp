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

ll t,n,x,e,o,mx,a,i;

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
		e=0;o=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a%2==1) o++;
			if(a%2==0) e++;
		}
		if(o==0)
		{
			cout<<"No\n"; continue;
		}
		mx = min(o - (1 - (o%2)),x - (1 - (x%2)));
		// cout<<"mx : "<<x-mx<<"\n";
		if(e>= x-mx) cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}