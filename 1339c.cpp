#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

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
ll t,n,a[MAX],d,cur,po,ans,temp,i;
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
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		d=0;
		for(i=1;i<n;i++)
		{
			cur = a[i-1]-a[i];
			if(cur>0) a[i]+=cur;
			d = max(d,cur);
		}
		po=0;
		ans=0;
		temp=d;
		while(temp>0)
		{
			cur = temp%2;
			if(cur==1)
				ans = max(ans,po);
			temp=temp/2;
			po++;
		}
		if(d==0) cout<<"0\n";
		else
		 cout<<ans+1<<"\n";
	}
	return 0;
}