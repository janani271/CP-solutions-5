#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 1000000000

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll p[100000],cur,i,len,t,n,ans;

void solve()
{
	p[0]=0;
	i=1;
	while(p[i-1] + (2*i) + (i-1)<=MAX)
	{
		p[i] = p[i-1] + (2*i) + (i-1);
		i++;
	}
	len = i;
}

ll check(ll x)
{
	auto pos = upper_bound(p,p+len,x);
	if(pos!=p+len) return p[pos-p-1];
	return p[len-1];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>t;
	solve();
	while(t--)
	{
		ans=0;
		cin>>n;
		do{
			cur = check(n);
			if(cur>0) ans++;
			n -= cur;
			// cout<<"cur : "<<cur<<"\n";
		}while(cur!=0);
		cout<<ans<<"\n";
	}
	return 0;
}