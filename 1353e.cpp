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

ll t,n,k,i,s[MAX],dp[MAX][4],o[MAX];
string str;

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
		cin>>str;
		for(i=1;i<=n;i++)
		{
			s[i] = str[i-1]-'0';
			
			dp[i][0] = dp[i][1] = 0;
			
			if(s[i]==1) o[i] = 1; 
			else o[i] = 0;
			if(i>1) o[i] += o[i-1];
			// cout<<"i : "<<i<<"\tones : "<<o[i]<<"\n";
		}
		for(i=1;i<=k;i++)
		{
			if(s[i]!=0) dp[i][0]++;
			else 		dp[i][1]++;
			if(i>1)
			{
				dp[i][0] += min(dp[i-1][0],dp[i-1][1]);
				dp[i][1] += o[i-1];
			}
			// cout<<"i : "<<i<<"\tdp0 : "<<dp[i][0]<<"\tdp1 : "<<dp[i][1]<<"\n";
		}
		for(i=k+1;i<=n;i++)
		{
			if(s[i]!=0) dp[i][0]++;
			else 		dp[i][1]++;
			
			dp[i][0] += min(dp[i-1][0],dp[i-1][1]);
			
			dp[i][1] += (dp[i-k][1] + o[i-1] - o[i-k]);
			dp[i][1] = min(dp[i][1],o[i-1]+(1-s[i]));
			
			// cout<<"i : "<<i<<"\tdp0 : "<<dp[i][0]<<"\tdp1 : "<<dp[i][1]<<"\n";
		}
		cout<<min(dp[n][0],dp[n][1])<<"\n";
	}
	return 0;
}