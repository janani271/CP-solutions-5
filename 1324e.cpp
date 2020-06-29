#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 2005

ll MOD=1e9+7;
ll n ,h , l , r , i , a[MAX], ans, dp[MAX][MAX];

ll good_sleep(ll t, ll x)
{
	if(t==n) return 0;
	if(dp[t][x]!=-1) return dp[t][x];

	ll aa , b , c , d;
	aa = (x+a[t])%h;
	b = (x+a[t]-1)%h;

	c = good_sleep(t+1,aa);
	if(l<=aa && aa<=r) c++;
	d = good_sleep(t+1,b);
	if(l<=b && b<=r) d++;
	
	return dp[t][x] = max(c,d);
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>h>>l>>r;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(dp,-1,sizeof dp);
	ans = good_sleep(0,0);
	cout<<ans;
	return 0;
}