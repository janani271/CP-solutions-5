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
ll t,i,n,a,ef,pose;
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
		ef=0; pose=-1;
		for(i=0;i<n;i++)
		{
			cin>>a;
			if(a%2==0)
			{
				ef=1;
				pose=i+1;
			}
		}
		if(ef)
		{
			cout<<"1\n";
			cout<<pose<<"\n";
		}
		else
		{
			if(n<=1) cout<<"-1\n";
			else
			{
				cout<<"2\n1 2\n";
			}
		}
	}
	return 0;
}