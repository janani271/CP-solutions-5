#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 2000000

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll t,n,i,dp[MAX+5];

void calc()
{
	dp[1]=0;
	dp[2]=0;
	for(i=3;i<=MAX;i++)
	{
		dp[i] = add(dp[i-1],2*dp[i-2]);
		//4 is for root vertex. for those levels%3!=0, the inner claws are picked such that
		// the root node cannot be used. and it is not counted in the regular answer either.
		// so when we can use it, we are adding a plus 4.
		if(i%3==0) dp[i] = add(dp[i], 4);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	calc();
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}