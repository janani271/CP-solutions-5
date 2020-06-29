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

ll t,n,k,i,a[MAX],flag,j,temp,res[MAX];
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
		m.clear();
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			m[a[i]]++;
		}
		if(m.size()>k)
		{
			cout<<"-1\n";
			continue;
		}

		ll cur=1;
		while(m.size()<k) m[cur++]++;
		
		cout<<(n*k)<<"\n";
		
		for(i=1;i<=n;i++)
		{
			for(auto it:m) cout<<it.first<<" ";
		}
		cout<<"\n";
	}
	return 0;
}