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

ll t,n,i,j,s[MAX],dp[MAX],mx;
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
		memset(dp,0,sizeof dp);
		mx=1;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>s[i];
			dp[i]=1;
		}
		for(i=2;i<=n;i++)
		{
			for(j=1;j*j<=i;j++)
			{
				if(i%j==0)
				{
					if(s[i]>s[j]) dp[i] = max(dp[i],dp[j]+1);
					if(j!=1 && s[i]>s[i/j]) dp[i] = max(dp[i],dp[i/j]+1);
				}
			}
			mx = max(mx,dp[i]);
		}
		cout<<mx<<"\n";
	}
	return 0;
}