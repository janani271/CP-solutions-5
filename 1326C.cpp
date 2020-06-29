#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 200005

ll MOD=998244353;
ll n , k , m , mv , p , len , c , i;
vector<ll>v;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	cin>>n>>k;
	m = n-k;
	mv = ((n*(n+1))/2) - ((m*(m+1))/2);
	for(i=1;i<=n;i++)
	{
		cin>>p;
		if(p>m) v.pb(i);
	}
	len = v.size();
	c=1;
	for(i=0;i<len-1;i++)
	{
		c = ((c%MOD) * ((v[i+1]-v[i])%MOD))%MOD;
	}
	cout<<mv<<" "<<c;
	return 0;
}