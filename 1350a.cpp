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


ll val(ll x)
{
	ll cur=3;
	while(x%cur!=0)
	{
		cur += 2;
	}
	return cur;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(n%2==0) cout<<n+(k*2)<<"\n";
		else cout<<n+(2*(k-1))+val(n)<<"\n";
	}
	return 0;
}