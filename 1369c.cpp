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

ll t,n,k,a[MAX],w[MAX],sum,i,j;

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
		for(i=0;i<n;i++) cin>>a[i];
		for(i=0;i<k;i++) cin>>w[i];
		sort(a,a+n,greater<ll>());
		sort(w,w+k);
		sum=0;
		for(i=0;i<k;i++)
		{
			sum += a[i];
			if(w[i]==1) sum += a[i];
		}
		j=k-1;
		for(i=0;i<k;i++)
		{
			if(w[i]==1) continue;
			j = j+(w[i]-1);
			sum += a[j];
		}
		cout<<sum<<"\n";
	}
	return 0;
}