#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 1000003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

string s,t;
ll n,c1,c2,i,a[MAX];

ll sum(ll x)
{
	ll finmax=0,curmax=0;
	for(i=0;i<n;i++)
	{
		curmax += x*a[i];
		finmax = max(curmax,finmax);
		curmax = max((ll)0,curmax);
	}
	return finmax;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	cin>>s>>t;
	c1=0; c2=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='0') c1++;
		if(t[i]=='0') c2++;
	}
	if(c1!=c2)
	{
		cout<<"-1";
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(s[i]!=t[i])
		{
			if(s[i]=='1') a[i]=1;
			else a[i]=-1;
		}
	}
	cout<<max(sum(-1),sum(1));
	return 0;
}