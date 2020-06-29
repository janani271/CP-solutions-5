#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 2000000000000000005

using namespace std;

ll MOD=1e9+7;

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
ll fpow(ll n, ll k, ll p = INF) 
{	ll r = 1; 
	for (; k; k >>= 1)
	{
		if (k & 1) r = r * n%p; 
		n = n * n%p;
	} 
	return r;
}

ll t,nr,ng,nb,i;
vll r,g,b;

ll calc(vll x, vll y, vll z)
{
	ll ans = INF;
	for(auto it:x)
	{
		//bigger element
		auto c = lower_bound(y.begin(),y.end(),it);
		if(c==y.end()) continue;
		//smaller element
		auto d = upper_bound(z.begin(),z.end(),it);
		if(d==z.begin()) continue;
		d--;

		ll cur = fpow(it-(*c),2) + fpow(it-(*d),2) + fpow((*d)-(*c),2);
		ans = min(ans,cur);
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll x;
	cin>>t;
	while(t--)
	{
		cin>>nr>>ng>>nb;
		r.clear(); g.clear(); b.clear();
		for(i=0;i<nr;i++)
		{
			cin>>x;
			r.pb(x);
		}
		for(i=0;i<ng;i++)
		{
			cin>>x;
			g.pb(x);
		}
		for(i=0;i<nb;i++)
		{
			cin>>x;
			b.pb(x);
		}
		sort(r.begin(),r.end());
		sort(g.begin(),g.end());
		sort(b.begin(),b.end());
		ll res1 = calc(r,g,b);
		ll res2 = min(res1,calc(r,b,g));
		ll res3 = min(res2,calc(g,r,b));
		ll res4 = min(res3,calc(g,b,r));
		ll res5 = min(res4,calc(b,r,g));
		ll res6 = min(res5,calc(b,g,r));
		cout<<res6<<"\n";
	}
	return 0;
}