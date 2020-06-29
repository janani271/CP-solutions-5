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
ll t,n,k;
ll a[MAX],peak[MAX];
ll mx,ans,idx;
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
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
		}
		memset(peak,0,sizeof peak);
		ans = 0; idx = 0;
		for(ll i=1;i<n-1;i++)
		{
			if(a[i]>a[i-1] && a[i]>a[i+1])
				peak[i] = 1;
			if(i<k-1) ans += peak[i];
		}
		mx = ans;
		// cout<<"mx befoe : "<<mx<<"\n";
		for(ll i=1;i+k<=n;i++)
		{
			if(peak[i]) ans--;
			if(a[i+k-2]>a[i+k-3] && a[i+k-2]>a[i+k-1]) ans++;
			// cout<<" l : "<<i+1<<"\tr : "<<i+k<<"\tans : "<<ans<<"\n";
			if(ans>mx)
			{
				mx = ans;
				idx = i;
			}
		}
		cout<<mx+1<<" "<<idx+1<<"\n";
	}
	return 0;
}