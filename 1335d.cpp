#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 50
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
ll t,i,j;
string a[MAX];
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
		for(i=0;i<9;i++)
		{
			cin>>a[i];
		}
		ll c=0; i=0;
		while(i<9)
		{
			ll temp=c;
			while(temp<9 && i<9)
			{
				if(a[i][temp]!='9') a[i][temp]='9';
				else a[i][temp] = '1';
				temp+=3; i++;
			}
			c++;
		}
		for(i=0;i<9;i++) cout<<a[i]<<"\n";
	}
	return 0;
}