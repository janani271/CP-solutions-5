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

ll n,k,c,i,x,a[MAX],t;

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
		c=0;
		for(i=0;i<n;i++)
		{
			cin>>x;
			if(x<k) a[i]=0;
			else if(x==k) a[i]=1;
			else a[i]=2;
			if(a[i]==1) c++;
		}
		if(c==0)
		{
			cout<<"no\n";
			continue;
		}
		c=0;
		for(i=1;i<n;i++)
		{
			if(a[i]>0 && a[i-1]>0)
			{
				c=1; break;
			}
			if(i>1 && a[i]>0 && a[i-2]>0)
			{
				c=1; break;
			}
		}
		if(c==0 && n>1)
		{
			cout<<"no\n";
			continue;
		}
		cout<<"yes\n";
	}
	return 0;
}