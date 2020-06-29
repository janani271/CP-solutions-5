#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 2003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,k,i,j,cur,dist[MAX][12],d;
ll dp[MAX][MAX],ans[MAX][MAX];
string num[MAX];
vll res;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;


	cin>>n>>k;
	string digits[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	for(i=1;i<=n;i++)
	{
		cin>>num[i];
		for(cur=0;cur<=9;cur++)
		{
			dist[i][cur] = 0;
			for(d=0;d<7;d++)
			{
				if(num[i][d]=='1' && digits[cur][d]=='0')
				{
					dist[i][cur] = -1;
					break;
				}
				else if(num[i][d]=='0' && digits[cur][d]=='1') dist[i][cur]++;
			}
		}
	}
	
	memset(dp,-1,sizeof dp);
	dp[n+1][0]=0;

	for(i=n;i>=1;i--)
	{
		for(j=0;j<=k;j++)
		{
			for(cur=0;cur<=9;cur++)
			{
				if(dist[i][cur]>j || dist[i][cur]==-1) continue;
				if(dp[i+1][j-dist[i][cur]]!=-1) dp[i][j] = cur;
			}
			if(dp[i][j]!=-1)
			{
				ans[i][j] = j-dist[i][dp[i][j]];
				// cout<<"i : "<<i<<"\tj : "<<j<<"\tval : "<<dp[i][j]<<"\n";
				// cout<<"move : "<<ans[i][j]<<"\n";
			}
		}
	}

	if(dp[1][k] == -1) cout<<"-1";
	else
	{
		cur = k;
		for(i=1;i<=n;i++)
		{
			res.push_back(dp[i][cur]);
			cur = ans[i][cur];
		}
		// reverse(res.begin(),res.end());
		for(auto it:res) cout<<it;
	}
	return 0;
}