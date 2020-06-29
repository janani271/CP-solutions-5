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

ll p[35],i,t,n,len,sum;
vll v,res;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	p[0] = 1;
	for(i=1;i<=30;i++) p[i] = 2*p[i-1];
	cin>>t;
	while(t--)
	{
		cin>>n;
		
		v.clear(); res.clear(); sum=1; len=1; v.pb(1);
		while(sum<n)
		{
			if(sum+p[len]>n) break;
			sum += p[len];
			len++;
			v.pb(sum);
		}
		if(n-sum>0)
		{
			v.pb(n); len++;
		}

		for(i=len-1;i>0;i--) v[i] = v[i]-v[i-1];
		sort(v.begin(),v.end());
		
		for(i=1;i<len;i++) res.pb(v[i]-v[i-1]);
		cout<<res.size()<<"\n";
		for(auto it:res) cout<<it<<" ";
		cout<<"\n"; 
	}
	return 0;
}