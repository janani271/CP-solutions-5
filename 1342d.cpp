#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,k,i,p[MAX],s[MAX],x,l,r,mid,ans,a[MAX];
vll res[MAX];

bool check(ll cur)
{
	bool flag=true;
	for(i=k;i>=1;i--)
	{
		if(p[i]>(cur*s[i]))
		{
			flag=false; break;
		}
	}
	return flag;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a[i] = x;
		p[x]++;
	}
	
	for(i=1;i<=k;i++)
	{
		cin>>s[i];
	}
	for(i=k;i>=1;i--)
	{
		p[i] += p[i+1];
	}
	
	l=1; r=n; ans=n;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(check(mid))
		{
			ans = min(ans,mid);
			r = mid-1;
		}
		else l=mid+1;
	}
	
	sort(a+1,a+n+1);

	for(i=1;i<=n;i++) res[i%ans].pb(a[i]);

	cout<<ans<<"\n";
	for(i=0;i<ans;i++)
	{
		cout<<res[i].size()<<" ";
		for(auto it:res[i]) cout<<it<<" ";
		cout<<"\n";
	}
	return 0;
}