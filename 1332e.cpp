#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

using namespace std;

ll MOD=998244353;

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

// fast exp
ll fpow(ll n, ll k, ll p = MOD) 
{	ll r = 1; 
	for (; k; k >>= 1)
	{
		if (k & 1) r = r * n%p; 
		n = n * n%p;
	} 
	return r;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	ll n,m,l,r,d,even,odd,a,b,tot,tc;
	cin>>n>>m>>l>>r;
	d = (r-l+1);
	even = d/2+(d%2);
	odd = d/2;
	tc = mul(n,m);
	a = fpow(even,tc);
	b = fpow(odd,tc);
	tot = add(a,b);
	cout<<tot;
	return 0;
}