#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 500003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll t,n,k,i,p[MAX],a[MAX],cur,x,y,ans;
map<ll,ll>m;

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
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(i=0;i<=(2*k);i++) p[i]=0;
		m.clear();
		for(i=1;i<=n/2;i++)
		{
			x = a[i]; y = a[n-i+1];
			p[min(x,y)+1] += 1;
			p[max(x,y)+k+1] -= 1;
			cur = x + y;
			m[cur]++;
		}
		p[1]=0; ans = n;
		for(i=2;i<=(2*k);i++)
		{
			p[i] = p[i] + p[i-1];
			cur = (p[i]-m[i]) + (((n/2)-p[i])*2);
			// cout<<"i : "<<i<<"\n";
			// cout<<"p : "<<p[i]<<"\tm : "<<m[i]<<"\n";
			ans = min(ans,cur);
		}
		cout<<ans<<"\n";	

	}
	return 0;
}