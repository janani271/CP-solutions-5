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

ll t,a,b,q,l,r,p[MAX],i,val,x,y;
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
		cin>>a>>b>>q;
		p[0]=0;
		for(i=1;i<=(a*b);i++)
		{
			p[i] = p[i-1];
			if((i%a)%b != (i%b)%a) p[i]++;
		}
		val = (a*b);

		for(i=1;i<=q;i++)
		{
			cin>>l>>r;
			x = (p[val]*(r/val)) + p[r%val];
			y = (p[val]*((l-1)/val)) + p[(l-1)%val];
			cout<<x-y<<" "; 	
		}
		cout<<"\n";
	}	
	return 0;
}