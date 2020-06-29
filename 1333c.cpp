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

ll n,p[MAX],a[MAX],sum,i,pre;
map<ll,ll>m;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	p[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i] = p[i-1] + a[i];
	}

	m[0]=1;
	pre=0; i=0;
	sum=0;
	while(pre<n)
	{
		while(i<n && m[p[i+1]]!=1)
		{
			i++;
			m[p[i]]=1;
		}
		sum += (i-pre);
		m[p[pre]] = 0;
		pre += 1;
	}
	cout<<sum<<"\n";
	return 0;
}